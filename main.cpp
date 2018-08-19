#include <iostream>
#include <random>
#include <chrono>
#include <Windows.h>

int main() {
    int rounds, sets, base, win, total, payOut;
    double maxSet = 0, minSet = 0, maxRound, minRound;
    double curBet, curCount;
    int totalWin = 0, totalLoss = 0, roundWin, roundLoss;

    unsigned seed1 = unsigned(std::chrono::system_clock::now().time_since_epoch().count());
    std::minstd_rand randInt (seed1);
    int maxAccept = randInt.max();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////        Values to change for different simulations        /////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    rounds = 100;
    sets = 100;
    base = 15;
    win = 18;
    total = 38;
    payOut = 2;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    maxAccept -= randInt.max() % (total);

    std::cout << "rounds per set : " << rounds << std::endl
              << "sets : " << sets << std::endl
              << "base bet : " << base << std::endl
              << "winning outcomes : " << win << std::endl
              << "total outcomes : " << total << std::endl
              << "payout on win : " << payOut << std::endl;

    for (int i = 0; i < sets; i++) {
        std::cout << std::endl;

        curBet = base;
        curCount = 0;
        maxRound = 0;
        minRound = 0;
        roundWin = 0;
        roundLoss = 0;

        for (int j = 0; j < rounds; j++) {
            int prob = randInt();
            do { // make sure there is even possibility of each number (1-4 mod 3 leaves more options for 1 than 2)
                prob = randInt();
            } while(prob > maxAccept);

            prob %= total; // make prob 0 : (total - 1)
            prob++; // make prob 1 : total

            curCount -= curBet;

            if (curCount < minRound) { // check for new low
                minRound = curCount;
            }

            if (prob <= win) { // win
                curCount += curBet * payOut;
                curBet = base;
                totalWin++;
                roundWin++;
            } else { // loss
                curBet *= 2;
                totalLoss++;
                roundLoss++;
            }

            if (curCount > maxRound) { // check for new high
                maxRound = curCount;
            }
        }

        std::cout << "Final : " << curCount << std::endl
                  << "Max round : " << maxRound << std::endl
                  << "Min round : " << minRound << std::endl
                  << "Wins : " << roundWin << " Losses : " << roundLoss << std::endl;

        if (maxRound > maxSet) maxSet = maxRound;
        if (minRound < minSet) minSet = minRound;
    }

    std::cout << std::endl;

    std::cout << "Max set : " << maxSet << std::endl
              << "Min set : " << minSet << std::endl
             << "Wins : " << totalWin << " Losses : " << totalLoss << std::endl;
}