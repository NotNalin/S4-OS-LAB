echo "Enter your current age"
read age
echo "Enter current year"
read year
if [ $age -ge 50 ]
then
    year_50=$((year-(age-50))
    echo "You turned 50 in the year $year_50"
else
    year_50=$((year-age+50))
    echo "You will turn 50 in the year $year_50"
fi
