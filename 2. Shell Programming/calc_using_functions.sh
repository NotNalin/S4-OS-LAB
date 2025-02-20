add()
{
    c=$((x+y))
    echo "Sum is $c"
}
sub()
{
    c=$((x-y))
    echo "Difference is $c"
}
mul()
{
    c=$((x*y))
    echo "Product is $c"
}
div()
{
    if [ $y -ne 0 ]
    then
        c=$((x/y))
        echo "Quotient is $c"
    else
        echo "Error: Division by 0"
    fi
}
echo "Enter Two Numbers"
read x
read y
echo -e "1.Add \n2.Subtract \n3.Multiply \n4.Divide \n5.Exit"
ch=0
while [ $ch -ne 5 ]
do
    echo "Enter choice"
    read ch
    if [ $ch -eq 1 ]
    then
        add
    elif [ $ch -eq 2 ]
    then
        sub
    elif [ $ch -eq 3 ]
    then
        mul
    elif [ $ch -eq 4 ]
    then
        div
    elif [ $ch -eq 5 ]
    then
        break
    else
        "Invalid choice"
    fi
done
