# weekly63

-----------------

### Install Nodejs over nvm to have control over different node versions

<https://github.com/nvm-sh/nvm>


### create a project with nextjs 13

```
npx create-next-app something
```

-----------------

### Docker

### RQlite - SQL

<https://github.com/rqlite/rqlite>

#### DB - Server

```ts
docker run -p4001:4001 --name rqlite_vm1 rqlite/rqlite 

```

#### DB - Client

<https://github.com/rqlite/rqlite/blob/master/DOC/CLI.md>

```ts
docker exec -it rqlite_vm1  rqlite

```

```sql
127.0.0.1:4001> create table products (id INTEGER NOT NULL PRIMARY KEY, pname TEXT, pprice DOUBLE)
0 row affected
127.0.0.1:4001> .tables
+----------+
| name     |
+----------+
| products |
+----------+
```

```sql
127.0.0.1:4001> .schema
+------------------------------------------------------------------------------------+
| sql                                                                                |
+------------------------------------------------------------------------------------+
| CREATE TABLE products (id INTEGER NOT NULL PRIMARY KEY, pname TEXT, pprice DOUBLE) |
+------------------------------------------------------------------------------------+

```

```sql
127.0.0.1:4001> INSERT INTO products (pname, pprice)values('Thinkpad T480',1000)
1 row affected
127.0.0.1:4001> select * from products
+----+---------------+--------+
| id | pname         | pprice |
+----+---------------+--------+
| 1  | Thinkpad T480 | 1000   |
+----+---------------+--------+

```

#### DB - SQLite Quety Language 

<https://www.sqlite.org/lang.html>

#### DB - Server - remove container
```
docker rm rqlite_vm1
```

-----------------

### git

- git commit message

```
git add .
git commit -m "this is a simple message, just head commit message"
```

- git commit message and boby

```
git add .
git commit -m "feat(msg): adding message and body

to the commit message
so we can search and find
into everything over regexp
"

```

- git log


- git log --all-match

```
git log --grep=feat --all-match
git log --grep=body 
git log --grep=body --all-match
```

- search in all log in all branches
```
git log --grep=body --all
```

- git grep ( search into the content of text files )
```
git grep TODO

src/index.ts:// TODO: add one
src/index.ts:// TODO: add two
src/index.ts:// TODO: add three
```

- JCL Mainframe IBM - Unix 
```
https://www.youtube.com/watch?v=UOL0HtlXVKM&t=331s

http://wotho.ethz.ch/tk4-/

debian@debian:~/projects/weekly63$ git config pull.rebase false

root@debian:~# apt install x3270

debian@debian:~/projects/weekly63$ mkdir mvs3801
debian@debian:~/projects/weekly63$ cd mvs3801
debian@debian:~/projects/weekly63/mvs3801$ 



```

```
unzip tk4...zip
cd unattended
./set_console_mode
cd ..
./mvs
... running ...


...
x3270 localhost:3270
user: herc01
pass: 
```
