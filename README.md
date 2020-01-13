Testing Repo for an Ancient Greek SQLite collation

https://www.sqlite.org/loadext.html
https://www.sqlite.org/c3ref/create_collation.html
https://www.sqlite.org/howtocompile.html
https://stackoverflow.com/questions/30898113/how-to-compile-an-extension-into-sqlite

https://stackoverflow.com/questions/16806570/how-do-i-compare-characters-in-custom-sqlite-collation-in-objective-c

//1. compile extension
gcc -pedantic -fPIC -shared hcgreekSQLiteCollation.c accent.c utilities.c -o hcgreek.dylib
 
//2. comile sqlite
gcc -DHAVE_READLINE -omysqlite shell.c sqlite3.c -lpthread -ldl -lreadline
 
//3. launch
./mysqlite hcdatadb1-5.sqlite

//4. load extension and query
.load hcgreek

select lemma from hqvocab order by lemma collate hcgreek limit 20;
