ifort ./iandTest.f90 -o  ./iandt.o
ifort ./miscTest.f90 -o ./mt.o
echo "iandTest.f90" >> output.txt
echo "******************" >> output.txt
./iand >> output.txt

echo "miscTest.f90" >> output.txt
echo "******************" >> output.txt
./mt.o >> output.txt