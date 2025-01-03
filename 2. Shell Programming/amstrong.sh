echo "Enter a number"
read n
temp=$n
result=0
len=0
while (($temp>0))
do
    temp=$((temp/10))
    len=$((len+1))
done
temp=$n
while (($temp>0))
do
    num=$((temp%10))
    temp=$((temp/10))
    result=$((result + (num**len)))
done
if [ $result -eq $n ]
then
    echo "$n is an Armstrong number"
else
    echo "$n is not an Armstrong number"
fi