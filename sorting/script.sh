echo "Printing random_gen.exe to inp.txt..."
./random_gen > inp.txt
echo "Feeding inp.txt to quicksort.exe"
echo
echo
./quicksort < inp.txt
echo
echo
echo "Feeding inp.txt to merge_sortc.exe"
echo
echo
./merge_sortc < inp.txt
echo
echo


