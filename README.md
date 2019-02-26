# Roulette Betting Simulator

This is a simple program which attempts to simulate roulette betting. Specifically, this is testing how effective the martingale betting strategy would actually be.

The Martingale strategy is usually applied to games with even odds. The player will choose a base betting value. Upon losing a round, the player will double their bet and upon winning a round, the play will return to their base betting value. The idea is that you are always covering your losses.

For example, let us lose three rounds then win one with a base betting value of 15 and a 1:1 payout. If no change in betting value occurs, then three losses will result in a lose of 45 units. The single win will result in a net lose of 30. Now with the Martingale strategy, the first lose results in a lost of 15. The second bet will be of 30 units as 15 is doubled. This results in a net lose of 45. The third bet will be of 60 units which results in a net lose of 105 units. The fourth bet will be of 120 units, which is won, which results in a net of 15 units won. 

This illustrates the idea that after every win, you replace all that you just lost and still win one times your base betting value. This way after 100 loses, a single win will still put you in the black. The problem is that the amount that needs to be bet each round increases exponentially as it is continuously doubled.

This program uses time seeded psuedo-random number generators to simulate a roulette wheel, at least with the default values. This was written in an attempt to see approxamitely how much one will vs how much one will win with this strategy.

# Usage

The following are the main variables used. There are default values which mimic red / black, even / odd, or high / low betting which all have the same odds of 18 winning spots out of 38 total in American roulette and have a 1:1 payout. These variables can be changed at runtime.

* rounds per set
	* total number of rounds to simulate in one set
* number of sets
	* total number of sets to simulate
* base bet
	* starting bet after each win
* winning outcomes
	* how many positions result in a win
* total outcomes
	* how many positions are there in total
* payout on win
	* n:1 payouts where n is the input

As extra clarification, the program will loop while keeping track of net gain as well as current bet for the number of rounds specified. It will then reset all values and repeat from scratch. It will do this for the number of sets specified.

# Output

There are three types of blocks of output:

Set number __ data:
Final : ___
Max round : ___
Min round : ___
Wins : __ Losses : __

Variable values used:
rounds per set : ___
number of sets : ___
base bet : ___
winning outcomes : ___
total outcomes : ___
payout on win : ___

All sets data:
Max set : ____
Min set : ____
Wins : ____ Losses : ____

I believe these are all self-explanatory. The first block is outputted after each set. It shows the ending net value the player would have been at. Max round is the maximum that the player had during that whole set. The min round is the minimum that the player had throughout the whole set. Note that these values are initialized to 0 so max will never be negative and min will never be positive. The numbers represent how much money the player would have compared to when they started. Wins and losses is just a count of wins and losses throughout that set.

The second block is simply the variables the program was run with.

The third block is the summary of all sets. Max and min set are the same as max round and min round except for all sets instead of just for one set. Wins and losses again is just the total number of wins and losses across all sets.

# Extra notes

This is currently made for even odd games, or games with odds close to 50-50. The reason is that upon a loss, the new bet is just double the previous bet. This only properly applies when there is an approxamite even chance of winning and losing. I plan to add proper handling of odds that are not close to being even, but that math is proving to be more complicated than expected.

# Features to add

* Games or settings with non-even odds
* Tracking the max bet at a single time