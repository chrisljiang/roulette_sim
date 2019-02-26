#include <iostream>
#include <random>
#include <chrono>
#include <windows.h>

int main() {
    unsigned rounds, sets, base, win, total, payOut;
    double maxSet = 0, minSet = 0, maxRound, minRound;
    double curBet, curCount;
    unsigned totalWin = 0, totalLoss = 0, roundWin, roundLoss;

    unsigned seed1 = unsigned(std::chrono::system_clock::now().time_since_epoch().count());
    std::minstd_rand randInt (seed1);
    int maxAccept = randInt.max();

    char newVals = 'a';

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////        Values for default simulations        ///////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    rounds = 100;
    sets = 100;
    base = 15;
    win = 18;
    total = 38;
    payOut = 1;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // check if user wants to input new values
    std::cout << "Would you like to input values? [y/n]" << std::endl;
    std::cin >> newVals;

    while (newVals != 'y' && newVals != 'Y' && newVals != 'n' && newVals != 'N') {
        std::cout << "Input not recognized; please input again." << std::endl;
        std::cin >> newVals;
    }

    // input new values
    if (newVals == 'y' || newVals == 'Y') {
        std::cout << "Input new values" << std::endl
                  << "rounds per set : ";
        std::cin >> rounds;
        std::cout << "number of sets : ";
        std::cin >> sets;
        std::cout << "base bet : ";
        std::cin >> base;
        std::cout << "winning outcomes : ";
        std::cin >> win;
        std::cout << "total outcomes : ";
        std::cin >> total;
        std::cout << "payout on win : ";
        std::cin >> payOut;
    }

    // calculate maximum acceptable value so that all values have equal probability
    maxAccept -= randInt.max() % (total);

    // loop for all sets
    for (int i = 0; i < sets; i++) {
        std::cout << std::endl;

        curBet = base;
        curCount = 0;
        maxRound = 0;
        minRound = 0;
        roundWin = 0;
        roundLoss = 0;

        // loop for all rounds per set
        for (int j = 0; j < rounds; j++) {
            int prob = randInt();
            do { // make sure there is even possibility of each number ((1 : 4) mod 3 leaves more options for 1 than 2)
                prob = randInt();
            } while(prob > maxAccept);

            prob %= total; // make prob 0 : (total - 1)
            prob++; // make prob 1 : total

            // check for new low
            if (curCount < minRound) {
                minRound = curCount;
            }

            if (prob <= win) { // win
                curCount += curBet * payOut;
                curBet = base;
                totalWin++;
                roundWin++;
            } else { // loss
                curCount -= curBet;
                curBet *= 2;
                totalLoss++;
                roundLoss++;
            }

            // check for new high
            if (curCount > maxRound) {
                maxRound = curCount;
            }
        }

        // output set information
        std::cout << "Set number " << i << " data:" << std::endl
                  << "Final : " << curCount << std::endl
                  << "Max round : " << maxRound << std::endl
                  << "Min round : " << minRound << std::endl
                  << "Wins : " << roundWin << " Losses : " << roundLoss << std::endl;

        // store set info
        if (maxRound > maxSet) maxSet = maxRound;
        if (minRound < minSet) minSet = minRound;
    }

    // output used variable values
    std::cout << std::endl << "Variable values used:" << std::endl
              << "rounds per set : " << rounds << std::endl
              << "number of sets : " << sets << std::endl
              << "base bet : " << base << std::endl
              << "winning outcomes : " << win << std::endl
              << "total outcomes : " << total << std::endl
              << "payout on win : " << payOut << std::endl;

    // output all set info
    std::cout << std::endl << "All sets data:" << std::endl
              << "Max set : " << maxSet << std::endl
              << "Min set : " << minSet << std::endl
              << "Wins : " << totalWin << " Losses : " << totalLoss << std::endl;
}