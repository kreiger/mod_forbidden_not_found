mod_forbidden_not_found
=======================

Apache module to replace HTTP error 403 Forbidden with 404 Not Found.

To build:

    apt-get install apache2-dev
    make

To install, copy mod_forbidden_not_found.so to where you want it
and then update the Apache configuration to load it:

    LoadModule forbidden_not_found_module /path/to/mod_forbidden_not_found.so

Then restart Apache.
