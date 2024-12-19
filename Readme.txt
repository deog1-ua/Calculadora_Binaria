Daniela Estafanía Orellana González Y4150392X

PRÁCTICA 9

Alias de Git Creados
Se han creado los siguientes alias locales y globales para facilitar el uso de comandos Git:
    Alias Globales:
        git config --global alias.co checkout
        git config --global alias.ci commit
        git config --global alias.st status
        git config --global alias.br branch

    Alias Locales:
        Alias Localesgit config alias.lg "log --oneline --graph --all"
        git config alias.last "log -1 HEAD"
        git config alias.unstage "reset HEAD --"
        git config alias.df "diff"

Ramas Locales y Remotas
Se han creado las siguientes ramas locales y se han subido como remotas:

    feature-suma
    feature-resta
    feature-multiplicacion

Comandos para Crear y Subir las Ramas
    git branch feature-suma
    git branch feature-resta
    git branch feature-multiplicacion

    git push -u origin feature-suma
    git push -u origin feature-resta
    git push -u origin feature-multiplicacion

Uso de git bisect para Encontrar un Error
** Cabe aclarar que el a partir de aquí se trabaja en la rama "suma" con el objetivo de mantener la rama principal estable

Se ha introducido un error intencionado en la función addBinary y se han realizado varios commits adicionales. 
El error introducido es cambiar la línea: 
    bitset<BITS> result = num1.to_ulong() + num2.to_ulong();
por esta otra, para que reste en lugar de sumar:
    bitset<BITS> result = num1.to_ulong() - num2.to_ulong();

posteriormente se han realizado 3 commits con cambios mínimos para recrear de manera real lo que sería buscar un fallo dentro de commits.
Para la búsqueda de este commit se han realizado los siguientes pasos:
    1. Iniciar el bisect: git bisect start
    2. Marcar el commit actual como malo: git bisect bad
    3. Marcar el primer commit realizado como bueno: git bisect good id_commit

El id_commit se ha encontrado tras hacer git log y buscar el primer commit

Luego se vuelve a probar con git bisect bad y good hasta encontrar el commit que esté bien, en este caso solo hizo falta hacerlo una vez. 

al encontrarlo se hace: git bisect reset

se repara el código y se vuelve a hacer un commit y push con todo solucionado 



