#include <stdio.h>
#include <string.h>

/*Winning Condition Function (Horizontal & Vertical)*/
int horizontalVerticalWin(int isHorizontal, char spotLetter[3][3], char player)
{
    int i, j, counter;

    for (i = 0; i < 3; i++){
        counter = 0;
        for (j = 0; j < 3; j++){
            if (isHorizontal && spotLetter[i][j] == player){
                counter += 1;
            }
            if (!isHorizontal && spotLetter[j][i] == player){
            counter += 1;
            }
            if (counter == 3){
                return 1;
            }
        }
    }

    return 0;
}

/*Winning Condition Function (Diagonal)*/
int diagonalWin(int isDiagonalOne, char spotLetter[3][3], char player)
{
    if (isDiagonalOne
        && spotLetter[0][0] == player
        && spotLetter[1][1] == player
        && spotLetter[2][2] == player){
        return 1;
    }

    if (!isDiagonalOne
        && spotLetter[2][0] == player
        && spotLetter[1][1] == player
        && spotLetter[0][2] == player){
        return 1;
    }

    return 0;
}

/*Main Function*/
int main()
{
    int  spotNumber[3][3];
    char spotLetter[3][3];

    int  i, j, k;

    int  pickedSpot, option;
    char player = 'X', winner = '\0';

    int  didWin = 0, isTaken = 1;
    int  displayMatrix = 1, numberOfMoves = 0;
    int  runGame = 1, readSpot = 1, processSpot = 1;

    int  runCode = 1, toggle = 1;
    int  displayMenu = 1, displayRules = 0, displaySettings = 0, displayResult = 1;

    char toggleNumbers[4] = "Yes";


    // Code Start
    while (runCode){

    // Displays Main Menu
    while (displayMenu){

    option = 0; displayMatrix = 1; readSpot = 1; processSpot = 1;

    printf(" > TIC TAC TOE <\n\n\n");
    printf(" (1) Play\n");
    printf(" (2) Rules\n");
    printf(" (3) Settings\n");
    printf(" (4) Exit\n\n");
    printf(" ");
    scanf("%d", &option);

    while (option != 1 && option != 2 && option != 3 && option != 4){
        printf("\n Invalid option, please select again:\n");
        printf(" ");
        scanf("%d", &option);
    }

    switch(option){
    case 1:
        displayMenu = 0;
        runCode = 1;
        break;
    case 2:
        displayRules = 1;
        break;
    case 3:
        displaySettings = 1;
        break;
    case 4:
        displayMenu = 0;
        displayMatrix = 0;
        runGame = 0;
        readSpot = 0;
        processSpot = 0;
        runCode = 0;
        displayResult = 0;
        break;
    }

    if (!displayMenu)
    {break;}

    // Displays Settings Menu
    while (displaySettings){
     
        printf(" > SETTINGS <\n\n\n");
        printf(" (1) Display tile's number: %s\n\n", toggleNumbers);
        printf("\n (2) Back\n\n");
        printf(" ");
        scanf("%d", &option);

        while (option != 1 && option != 2){
            printf("\n Invalid option, please select again:\n");
            printf(" ");
            scanf("%d", &option);
        }

        if (option == 1){
            if (toggle == 1){
                strcpy(toggleNumbers, "No");
                toggle = 0;
            } else {
                strcpy(toggleNumbers, "Yes");
                toggle = 1;
            }

        } else {
            displaySettings = 0;
        }
    }

    // Displays Rules Menu
    while (displayRules){

        printf(" > GAME RULES <\n\n");
        printf("\n   I. To play, you must insert a tile number where your 'X' or 'O' will be replaced.");
        printf("\n  II. The first player will always be 'X'.");
        printf("\n III. A player cannot select a tile that has already been occupied.");
        printf("\n  IV. To win, a player must form a sequence of tiles horizontally, vertically, or diagonally.");
        printf("\n   V. Enter '0' (zero) when selecting a tile during the game to return to the menu.\n");
        printf("\n\n (1) Back\n\n");
        printf(" ");
        scanf("%d", &option);

        while (option != 1){
            printf("\n Invalid option, please select again:\n");
            printf(" ");
            scanf("%d", &option);
        }

    displayRules = 0;

    }

    } // Close displayMenu

    // Assign matrix values
    k = 1;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            spotNumber[i][j] = k;
            k++;
        }
    }

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            spotLetter[i][j] = 'I';
        }
    }


    // Displays initial matrix
    while (displayMatrix){

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (toggle){
                printf(" %d", spotNumber[i][j]);
            } else {
                printf(" %c", ' ');
            }

                if (i == 0 && j == 2)
                {break;}
                if (i == 1 && j == 2)
                {break;}
                if (i == 2 && j == 2)
                {break;}

                printf(" \xBA");
        }
        printf("\n");

        if (i == 2 && j == 2)
        {break;}

        printf(" \xCD\xCD\xCE\xCD\xCD\xCD\xCE\xCD\xCD\n");
    }

    displayMatrix = 0;

    } // Close displayMatrix

    // Process selected tile (runGame)
    do{

    numberOfMoves = 0;

    while (readSpot){

        printf("\n Player %c, select a tile\n\n", player);
        printf(" ");
        scanf("%d", &pickedSpot);

        while (pickedSpot < 0 || pickedSpot > 9){
            printf(" Invalid tile, please select again:\n");
            printf(" ");
            scanf("%d", &pickedSpot);
        }
        readSpot = 0;
        processSpot = 1;
    }

    if (pickedSpot == 0){
        processSpot = 0;
        runGame = 0;
        displayResult = 0;
        displayMenu = 1;
        break;
    }

    // Test if selected tile is valid
    isTaken = 1;
    while (isTaken){
        isTaken = 0;
        k = 1;
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++){
                if (pickedSpot == k && spotLetter[i][j] != 'I'){
                    isTaken = 1;
                    break;
                }
                k++;
            }
            if (isTaken)
            {break;}
        }
        if (isTaken){
            printf(" Tile already occupied!\n Please select again:\n\n");
            printf(" ");
            scanf("%d", &pickedSpot);
        }
    }

    // Update matrix values
    while (processSpot){

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (pickedSpot == spotNumber[i][j] && player == 'X'){
                spotNumber[i][j] = 0;
                spotLetter[i][j] = 'X';
            }
            if (pickedSpot == spotNumber[i][j] && player == 'O'){
                spotNumber[i][j] = 0;
                spotLetter[i][j] = 'O';
            }
        }
    }

    // Displays updated matrix
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (spotNumber[i][j]){
                if (toggle){
                    printf(" %d", spotNumber[i][j]);
                } else {
                    printf(" %c", ' ');
                }
            } else
            if (!spotNumber[i][j]){
                printf(" %c", spotLetter[i][j]);
            }

            if (i == 0 && j == 2)
            {break;}
            if (i == 1 && j == 2)
            {break;}
            if (i == 2 && j == 2)
            {break;}

            printf(" \xBA");
        }
        printf("\n");

        if (i == 2 && j == 2)
        {break;}

        printf(" \xCD\xCD\xCE\xCD\xCD\xCD\xCE\xCD\xCD\n");
    }

    // Horizontal and vertical win test
    didWin = horizontalVerticalWin(1, spotLetter, player) || horizontalVerticalWin(0, spotLetter, player);

    if (didWin){
        runGame = 0;
        processSpot = 0;
        winner = player;
        break;
    }

    // Diagonal win test
    didWin = diagonalWin(1, spotLetter, player) || diagonalWin(0, spotLetter, player);

    if (didWin){
        runGame = 0;
        processSpot = 0;
        winner = player;
        break;
    }

    // Update player
    if (player == 'X'){
        player = 'O';
    } else {
        player = 'X';
    }

    // Counts the rounds
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (spotNumber[i][j] == 0){
                numberOfMoves += 1;
            }
        }
    }

    // Test if game is over
    if (numberOfMoves == 9){
        runGame = 0;
    } else {
        runGame = 1;
    }

    readSpot = 1;
    processSpot = 0;
    displayResult = 1;

    } // Close processSpot

    } while (runGame); // Close "do"

    // Displays results
    while (displayResult){

    if (winner == 'X' || winner == 'O'){
        printf("\n Congratulations Player '%c' on the win!\n\n", winner);
    } else {
        printf("\n Draw!\n");
    }

    printf(" (1) New Game\n");
    printf(" (2) Back to Menu\n");
    printf(" (3) Exit Game\n\n");
    printf(" ");
    scanf("%d", &option);

    while (option != 1 && option != 2 && option != 3){
        printf("\n Invalid option, please select again:\n");
        printf(" ");
        scanf("%d", &option);
    }

    switch(option){
    case 1:
        displayMatrix = 1;
        readSpot = 1;
        processSpot = 1;
        break;
    case 2:
        runCode = 1;
        displayMenu = 1;
        break;
    case 3:
        runCode = 0;
        break;
    }

    displayResult = 0;

    } // Close displayResult

    player = 'X';

    } // Close runCode

    printf("\n Tic Tac Toe Finished.\n\n");

    return 0;
}