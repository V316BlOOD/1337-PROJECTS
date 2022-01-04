FROM debian:buster

WORKDIR /

COPY srcs/mysql-config/ .

RUN apt update -y \
&& apt upgrade -y \
&& apt install nginx -y \
&& apt install wget -y \
&& wget https://dev.mysql.com/get/mysql-apt-config_0.8.13-1_all.deb \
&& apt install lsb-release -y \
&& apt install gnupg -y \
&& apt update -y \
&& apt install expect -y \
&& sh expect1.sh \
&& apt update -y \
&& sh expect2.sh \
&& apt-get install php-fpm -y \
&& wget https://files.phpmyadmin.net/phpMyAdmin/5.0.0/phpMyAdmin-5.0.0-all-languages.zip \
&& apt-get install unzip -y \
&& unzip phpMyAdmin-5.0.0-all-languages.zip \
&& mv phpMyAdmin-5.0.0-all-languages var/www/html/phpmyadmin \
&& apt-get install php-mysql -y \
&& mkdir /etc/nginx/ssl \
&& apt install htop -y

WORKDIR /var/www/html/

COPY srcs/wordpress/ .

WORKDIR /etc/nginx/sites-available/

COPY srcs/php-conf/default .

WORKDIR /

COPY srcs/ssl/ etc/nginx/ssl/
COPY ./srcs/mysql-config/start.sh .
RUN chmod 777 start.sh

ENTRYPOINT ["/start.sh"]
