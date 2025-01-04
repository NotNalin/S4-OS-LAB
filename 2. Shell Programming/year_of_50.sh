echo "Enter your current age "
read age
echo "Enter the current year "
read year

if [ $age -ge 50 ]
then
    year_50=$((year + 50 - age))
    echo "You turned 50 in the year $year_50."
else
    year_50=$((year + 50 - age))
    echo "You will turn 50 in the year $year_50."
fi