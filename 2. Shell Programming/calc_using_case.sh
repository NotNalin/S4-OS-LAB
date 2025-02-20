echo "Enter Two Numbers"
read x
read y
echo -e "1.Add \n2.Subtract \n3.Multiply \n4.Divide"
echo "Enter your choice"
read ch
case $ch in
1)
    c=$((x+y))
    echo "Sum is $c"
    ;;
2)
    c=$((x-y))
    echo "Difference is $c"
    ;;
3)
    c=$((x*y))
    echo "Product is $c"
    ;;
4)
    if [ $y -ne 0 ]
    then
        c=$((x/y))
        echo "Quotient is $c"
    else
        echo "Error: Division by 0"
    fi
    ;;
*)
    echo "Invalid choice"
    ;;
esac
