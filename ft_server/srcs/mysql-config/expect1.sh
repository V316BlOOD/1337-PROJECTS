expect -c "
set timeout 100
spawn dpkg -i mysql-apt-config_0.8.13-1_all.deb
expect \"Which MySQL product do you wish to configure? \"
send \"1\r\"
expect \"Which server version do you wish to receive? \"
send \"1\r\"
expect \"Which MySQL product do you wish to configure? \"
send \"4\r\"
expect eof
"
