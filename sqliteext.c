/*
** 2017-04-16
**
** The author disclaims copyright to this source code.  In place of
** a legal notice, here is a blessing:
**
**    May you do good and not evil.
**    May you find forgiveness for yourself and forgive others.
**    May you share freely, never taking more than you give.
**
*************************************************************************
**
** This file implements a run-time loadable extension to SQLite that
** registers a sqlite3_collation_needed() callback to register a fake
** collating function for any unknown collating sequence.  The fake
** collating function works like BINARY.
**
** This extension can be used to load schemas that contain one or more
** unknown collating sequences.

https://stackoverflow.com/questions/30898113/how-to-compile-an-extension-into-sqlite
https://www.sqlite.org/loadext.html
//1. compile extension
gcc -fPIC -shared sqliteext.c -o anycollseq.dylib
 
//2. comile sqlite
gcc -DHAVE_READLINE -omysqlite shell.c sqlite3.c -lpthread -ldl -lreadline
 
//3. launch
./mysqlite hcdatadb1-5.sqlite

//4. load extension and query
.load anycollseq
select lemma from hqvocab order by lemma collate anycollseq limit 20;
 
*/
#include "sqlite3ext.h"
SQLITE_EXTENSION_INIT1
#include <string.h>
#include <stdio.h>
#include "accent.h"

static int anyCollFunc(
  void *NotUsed,
  int nKey1, const void *pKey1,
  int nKey2, const void *pKey2
){
    /*
  int rc, n;
  n = nKey1<nKey2 ? nKey1 : nKey2;
  rc = memcmp(pKey1, pKey2, n);
  if( rc==0 ) rc = nKey1 - nKey2;
    */
    
    int a = compareSort(nKey1, pKey1, nKey2, pKey2) * -1;
    fprintf(stderr, "s: %d\n", a);
    return a;
    
  //return rc * -1;
}

static void anyCollNeeded(
  void *NotUsed,
  sqlite3 *db,
  int eTextRep,
  const char *zCollName
){
  sqlite3_create_collation(db, zCollName, eTextRep, 0, anyCollFunc); 
}

#ifdef _WIN32
__declspec(dllexport)
#endif
int sqlite3_anycollseq_init(
  sqlite3 *db, 
  char **pzErrMsg, 
  const sqlite3_api_routines *pApi
){
  int rc = SQLITE_OK;
  SQLITE_EXTENSION_INIT2(pApi);
  rc = sqlite3_collation_needed(db, 0, anyCollNeeded);
  return rc;
}
