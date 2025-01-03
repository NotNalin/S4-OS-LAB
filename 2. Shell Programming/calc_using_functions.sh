add() 
{
    c=$((x + y))
    echo "Sum is $c"
}
sub()
{
    c=$((x - y))
    echo "Difference is $c"
}
mul()
{
    c=$((x * y))
    echo "Product is $c"
}
div()
{
    if [ $y -ne 0 ]
    then
        c=$((x / y))
        echo "Quotient is $c"
    else
        echo "Error: Division by zero is not allowed"
    fi
}
echo "Enter two numbers"
read x
read y
echo "Enter your choice"
choice=0
echo -e "1. Add \n2. Subtract \n3. Multiply \n4. Divide \n5. Exit"
while [ $choice -ne 5 ]
do
    read choice
    if [ $choice -eq 1 ]
    then
        add
    elif [ $choice -eq 2 ]
    then
        sub
    elif [ $choice -eq 3 ]
    then
        mul
    elif [ $choice -eq 4 ]
    then
        div
    elif [ $choice -eq 5 ]
    then
        break
    else
        echo "Invalid choice"
    fi
done