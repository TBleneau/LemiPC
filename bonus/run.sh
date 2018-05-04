for ((i = 0; i < 150; i += 1))
do
    ./lemipc './sources/main.o' 2 &
done

for ((i = 0; i < 150; i += 1))
do
    ./lemipc './sources/main.o' 3 &
done
for ((i = 0; i < 150; i += 1))
do
    ./lemipc './sources/main.o' 1 &
done
for ((i = 0; i < 150; i += 1))
do
    ./lemipc './sources/main.o' 7 &
done
wait
exit
