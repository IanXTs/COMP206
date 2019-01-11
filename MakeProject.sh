#bin/sh
#Ian Tsai MiniAssignment 2 260741766
cd ~
if [ ! -d project ]
then 
     mkdir project
fi 
cd ./project/

if [ ! -d cs206 ]
then
     mkdir cs206
fi 
cd ./cs206/
if [ -d $1 ]
then echo "This project name has already been used"
     exit 1
else 
     mkdir $1 archive backup docs assets database source
fi 

cd ./source
"#!bin/sh
cp 'ls | grep -i "\.[ch]$"' ../backup
echo 
     "You project directories have been created." > backup.sh
chmod 755 backup.sh
