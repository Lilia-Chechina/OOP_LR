Чтоб запустить LR
cmake ..
make 
touch log.txt test.txt в build
В таком формате вводить данные:
add Bear Teddy x 5 y 7
load {имя файла, откуда загрузить}
save {имя файла куда сохранить}

Убийцы медведя: разбойник
Убийцы оборотня: Медведь
Убийца разбойника: обротень

Поправить ошибку (мёртвые не могут атаковать)

root@571471f3a7b8:/workspaces/OOP_LABS/Lab_6var5/build# ./Lab_6var5_exe 
add Bear Teddy x 0 y 0
Sucess first wordSucess second word
add Thug Robin x 0 y 0
Sucess first wordSucess second word
add Werewolf Luis x 0 y 0
Sucess first wordSucess second word
fight 
Enter a distance
10
KILL: Bear Teddy {0, 0} was killed by Thug Robin {0, 0}
KILL: Thug Robin {0, 0} was killed by Werewolf Luis {0, 0}
KILL: Werewolf Luis {0, 0} was killed by Bear Teddy {0, 0}
Survivors: