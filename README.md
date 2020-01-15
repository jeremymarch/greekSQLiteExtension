Testing Repo for an Ancient Greek SQLite collation

//1. compile extension
gcc -pedantic -fPIC -shared hcgreekSQLiteCollation.c accent.c utilities.c -o hcgreek.dylib
 
//2. comile sqlite
gcc -DHAVE_READLINE -omysqlite shell.c sqlite3.c -lpthread -ldl -lreadline
 
//3. launch
./mysqlite hcdatadb1-5.sqlite

//4. load extension and query
.load hcgreek

select lemma from hqvocab order by lemma collate hcgreek limit 20;


Resources:

https://www.sqlite.org/loadext.html
https://www.sqlite.org/c3ref/create_collation.html
https://www.sqlite.org/howtocompile.html
https://stackoverflow.com/questions/30898113/how-to-compile-an-extension-into-sqlite


https://stackoverflow.com/questions/16806570/how-do-i-compare-characters-in-custom-sqlite-collation-in-objective-c

https://stackoverflow.com/questions/14688695/use-of-sqlite3-create-collation-on-iphone

https://stackoverflow.com/questions/7867099/how-can-i-create-a-user-defined-function-in-sqlite
https://stackoverflow.com/questions/51335923/sqlite-user-defined-function-with-index
http://sqlite.1065341.n5.nabble.com/Help-with-custom-collation-td93595.html
https://stackoverflow.com/questions/20942566/indexes-with-custom-collations-in-sqlite
https://www.metalliccode.com/writing-new-sql-functions

http://souptonuts.sourceforge.net/readme_sqlite_tutorial.html

From: https://www.sqlite.org/loadext.html
6. Statically Linking A Run-Time Loadable Extension
The exact same source code can be used for both a run-time loadable shared library or DLL and as a module that is statically linked with your application. This provides flexibility and allows you to reuse the same code in different ways.

To statically link your extension, simply add the -DSQLITE_CORE compile-time option. The SQLITE_CORE macro causes the SQLITE_EXTENSION_INIT1 and SQLITE_EXTENSION_INIT2 macros to become no-ops. Then modify your application to invoke the entry point directly, passing in a NULL pointer as the third "pApi" parameter.

It is particularly important to use an entry point name that is based on the extension filename, rather than the generic "sqlite3_extension_init" entry point name, if you will be statically linking two or more extensions. If you use the generic name, there will be multiple definitions of the same symbol and the link will fail.

Use: sqlite3_auto_extension() to register static extension globally!

If you will be opening multiple database connections in your application, rather than invoking the extension entry points for each database connection separately, you might want to consider using the sqlite3_auto_extension() interface to register your extensions and to cause them to be automatically started as each database connection is opened. You only have to register each extension once, and you can do so near the beginning of your main() routine. Using the sqlite3_auto_extension() interface to register your extensions makes your extensions work as if they were built into the core SQLite - they automatically exist whenever you open a new database connection without needing to be initialized. Just be sure to complete any configuration you need to accomplish using sqlite3_config() before registering your extensions, since the sqlite3_auto_extension() interface implicitly calls sqlite3_initialize().
