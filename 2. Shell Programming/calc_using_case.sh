echo "Enter two numbers"
read x
read y
echo "Enter your choice"
echo -e "1. Add \n2. Subtract \n3. Multiply \n4. Divide"
read choice
case $choice in
1)
   c=$((x + y))
   echo "Sum is $c"
   ;;
2)
   c=$((x - y))
   echo "Difference is $c"
   ;;
3)
   c=$((x * y))
   echo "Product is $c"
   ;;
4)
   if [ $y -ne 0 ]
   then
      c=$((x / y))
      echo "Quotient is $c"
   else
      echo "Error: Division by zero is not allowed"
   fi
   ;;
*)
   echo "Invalid choice"
   ;;
esac
