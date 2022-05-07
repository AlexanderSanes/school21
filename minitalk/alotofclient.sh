#! /bin/bash
for ((i=1;i<1001;i++))
do
	./client $1 "$(LC_ALL=C tr -dc 'A-Za-z0-9!"#$%&'\''()*+,-./:;<=>?@[\]^_`{|}~' </dev/urandom | head -c 13)${i}"
done