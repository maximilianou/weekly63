# weekly63

nothing in mind

### Install Nodejs over nvm to have control over different node versions

<https://github.com/nvm-sh/nvm>


### create a project with nextjs 13

```
npx create-next-app something
```

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