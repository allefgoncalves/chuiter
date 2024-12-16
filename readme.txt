Trabalho realizado por Allef G. e Tatiane A.
Para a diciplina de estrutura de dados, 
onde é abordado o estudo das arvores AVL e TRIE.

foi utilizado a arvore trie para guardar os nomes de usuarios
onde no ultimo nodo de cada usuario existe um ponteiro para uma 
arvore AVL onde são registrados os "chuiters" em ordem cronologica.

na arvore trie a função de busca que exibe todos os usuarios faz 
a busca em ordem alfabetica ou tambem é possivel fazer uma busca de 
um usuario expecifico.

ja na arvore AVL é utilizado a biblioteca times.h para converter o 
formato da data e hora em um numero inteiro no qual é ultilizado 
como chave para a organização em ordem cronologica, ja no mecanismo
de busca dos "chuiters" é verificado o intervalo de tempo no qual está 
as mensagens e exibido as mesnsagens em ordem cronologica.

link para o projeto no github:
https://github.com/allefgoncalves/chuiter