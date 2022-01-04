expect -c "
set timeout 100
spawn apt-get -y install mysql-server
expect \"Enter root password: \"
send \"root\r\"
expect \"Re-enter root password:\"
send \"root\r\"
expect eof
"
