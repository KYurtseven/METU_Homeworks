introfolder=$(pwd)
cd $introfolder

if [ -d "myoutputs" ]; then
  rm -rf myoutputs
fi

mkdir myoutputs
touch organized.txt

echo 'import Hw1' >> organized.txt

declare -i c=0
for i in {1..50}
do
    echo -ne "testcase$i = " >> organized.txt
	cat $introfolder/input/$i.in >> organized.txt
done

declare -i c=0
echo 'main = do' >> organized.txt
echo '	putStrLn "STARTING TEST" ' >> organized.txt
for j in {1..50}
do
    echo "	writeFile 'myoutputs/test$j.out' (show (next testcase$j))" >> organized.txt
done

eval " python clearmyoutputs.py"

touch "test.hs"
cat $introfolder/organized.txt >> "test.hs"
eval "ghc -o main test.hs -fno-warn-tabs"
eval "./main"

declare -i c=0
for j in {1..50}
do
    diff myoutputs/test$j.out output/$j.out && echo "case$j: pass" || echo "case$j: ERROR"
done

rm -f "test.o" "test.hi" "main" "test.hs" "Hw1.hi" "Hw1.o" "organized.txt"
