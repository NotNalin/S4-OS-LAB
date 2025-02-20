echo "Enter Number"
read n
temp=$n
result=0
len=0
while(($temp>0))
do
    temp=$((temp/10))
    len=$((len+1))
done
temp=$n
while(($temp>0))
do
    num=$((temp%10))
    temp=$((temp/10))
    result=$((result+num**len))
done
if(($n==$result))
then
    echo "$n is an amstrong number"
else
    echo "$n is not an amstrong number"
fi
