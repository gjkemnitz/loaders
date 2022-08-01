Thoughts about loaders:

Why another ETL loader?

Many existing ETL loaders are excessively complex and many are command-line
unfriendly.  etl_wiz will be purely command-line oriented, as simple as the
rather complex problem of ETL allows, and intended for use in scripted and
other command-line environments.

I won't bother with timers or such things; cron or systemctl do these quite
nicely.

Also, it will be coded in C and optimized for large-scale loading, where
"large scale" means "as big as possible and run as fast as possible".  Also,
the design should allow for loads to multiple database targets, as many big
environments are multi-instance.  

Why C?  Because I know it well and know how to write fast code in it.

Also, I will minimize use of third-party libraries except where they can't
be avoided, such as database connector packages.  Yes, this means that
there will be some "wheel reinvention" in this code, but so be it.

My "library rule" is to minimize support hassles, packaging complexity, and
license issues. 

1.  The overall design

2.  Config files

Configuration files are intended for human editing and will use the
"TOML format" discussed here:

https://toml.io/en

a. The db connection file

This contains info needed to connect to specific database instances,
such as hostname, host port, user name, user password, and the database name.
There may be db vendor specific data here.

b. Input data description file

The input data description file describes the format of input data
This will be separate from the db connection file so that we can allow
the same data description file to be used for loads to multiple database 
instances.  

This will include the following:

o Description of the input data with things like custom delimiters,
  custom record terminator characters, etc.
o For fixed-width formats, this will be where we store the record offsets
o Remapping directives will also be stored here. 
o In future versions where we do loads between databases, the extraction query
  will be stored here.

c. Runtime behavior description file

This will contain information such as 

1. How to behave upon errors.  Stop on first error?  Stop after N errors?
Continue until done, even though there are some errors?  
2. Where to put logging output.
3. Any other runtime behavior specifiers.

3. Runtime execution

A command line will look something like

etl_wiz -d [db-conf] -i [input-conf] -r [runtime-conf] input_file.csv

Environment variables:

ETL_DB_CONF - specifies a path to the db config file
ETL_INPUT_CONF - specifies a path to an input config file
ETL_RUNTIME_CONF - specifies a path to the runtime config file

Upgrade Plans

Version 1: CSV to MySQL as a target
Version 2: Add fixed record format files and Postgres as a target
Version 3: Use a database as a data source as well as a target
