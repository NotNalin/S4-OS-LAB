echo "Enter your current age "
read age
echo "Enter the current year "
read year

if [ $age -ge 50 ]
then
    echo "You are already 50 or older!"
else
    years_to_50=$((50 - age))
    year_of_50=$((year + years_to_50))
    echo "You will turn 50 in the year $year_of_50."
fi