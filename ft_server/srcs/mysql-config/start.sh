#!/bin/bash
service php7.3-fpm start
chown -R mysql: /var/lib/mysql
service mysql start
mysql -uroot -proot -e 'CREATE DATABASE wordpress;'
nginx -g "daemon off;"