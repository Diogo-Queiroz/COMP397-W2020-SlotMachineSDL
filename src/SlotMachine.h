// ReSharper disable CppClangTidyClangDiagnosticComment
#pragma once
#ifndef __SLOT_MACHINE__
#define __SLOT_MACHINE__
#include "DisplayObject.h"
#include "GameItemType.h"
#include <sstream>

class SlotMachine : public DisplayObject
{
public:
    static SlotMachine* Instance()
    {
	    if (s_pInstance == nullptr)
	    {
            s_pInstance = new SlotMachine();
            return s_pInstance;
	    }
        return s_pInstance;
    }
	
	SlotMachine();
	~SlotMachine();


	void draw() override;
	void update() override;
	void clean() override;
	void showPlayerStats();
    void resetFruitTally();
    void resetAll();
    void checkJackpot();
    void showWinMessage();
    void showLossMessage();
    bool checkRange(int value, int lowerBounds, int upperBounds);
    std::vector<std::string> reels();
    void determineWinnings();

	// Setters & Getters
	void setPlayerBet(int m_bet_value, GameItemType m_type);
	
    int getPlayerBet();
    int getPlayerMoney();
    int getJackpot();

	// Public members
    std::string m_fruits = "";
    float m_winRatio = 0.0f;
	int m_playerMoney = 1000;
    int m_winnings = 0;
    int m_jackpot = 5000;
    int m_turn = 0;
    int m_playerBet = 0;
    int m_winNumber = 0;
    int m_lossNumber = 0;
    std::vector<std::string> m_spinResult;
    int m_grapes = 0;
    int m_bananas = 0;
    int m_oranges = 0;
    int m_cherries = 0;
    int m_bars = 0;
    int m_bells = 0;
    int m_sevens = 0;
    int m_blanks = 0;
    std::string winRatioText = "0.00%";
    std::ostringstream winRatioStr;

	int m_spinResultIndex [3] = {0,0,0};
private:
	
protected:

    static SlotMachine* s_pInstance;
};

typedef SlotMachine TheSlotMachine;

#endif /* defined (__SLOT_MACHINE__) */
/**  // NOLINT(clang-diagnostic-comment, clang-diagnostic-comment, clang-diagnostic-comment, clang-diagnostic-comment)
    var playerMoney = 1000;
    var winnings = 0;
    var jackpot = 5000;
    var turn = 0;
    var playerBet = 0;
    var winNumber = 0;
    var lossNumber = 0;
    var spinResult;
    var fruits = "";
    var winRatio = 0;
    var grapes = 0;
    var bananas = 0;
    var oranges = 0;
    var cherries = 0;
    var bars = 0;
    var bells = 0;
    var sevens = 0;
    var blanks = 0;

    /* Utility function to show Player Stats
    function showPlayerStats()
    {
        winRatio = winNumber / turn;
        $("#jackpot").text("Jackpot: " + jackpot);
        $("#playerMoney").text("Player Money: " + playerMoney);
        $("#playerTurn").text("Turn: " + turn);
        $("#playerWins").text("Wins: " + winNumber);
        $("#playerLosses").text("Losses: " + lossNumber);
        $("#playerWinRatio").text("Win Ratio: " + (winRatio * 100).toFixed(2) + "%");
    }

    /* Utility function to reset all fruit tallies
    function resetFruitTally() {
        grapes = 0;
        bananas = 0;
        oranges = 0;
        cherries = 0;
        bars = 0;
        bells = 0;
        sevens = 0;
        blanks = 0;
    }

    /* Utility function to reset the player stats
    function resetAll() {
        playerMoney = 1000;
        winnings = 0;
        jackpot = 5000;
        turn = 0;
        playerBet = 0;
        winNumber = 0;
        lossNumber = 0;
        winRatio = 0;
    }


    /* Check to see if the player won the jackpot
    function checkJackPot() {
        /* compare two random values
        var jackPotTry = Math.floor(Math.random() * 51 + 1);
        var jackPotWin = Math.floor(Math.random() * 51 + 1);
        if (jackPotTry == jackPotWin) {
            alert("You Won the $" + jackpot + " Jackpot!!");
            playerMoney += jackpot;
            jackpot = 1000;
        }
    }

    /* Utility function to show a win message and increase player money
    function showWinMessage() {
        playerMoney += winnings;
        $("div#winOrLose>p").text("You Won: $" + winnings);
        resetFruitTally();
        checkJackPot();
    }

    /* Utility function to show a loss message and reduce player money
    function showLossMessage() {
        playerMoney -= playerBet;
        $("div#winOrLose>p").text("You Lost!");
        resetFruitTally();
    }

    /* Utility function to check if a value falls within a range of bounds
    function checkRange(value, lowerBounds, upperBounds) {
        if (value >= lowerBounds && value <= upperBounds)
        {
            return value;
        }
        else {
            return !value;
        }
    }

    /* When this function is called it determines the betLine results.
    e.g. Bar - Orange - Banana
    function Reels() {
        var betLine = [" ", " ", " "];
        var outCome = [0, 0, 0];

        for (var spin = 0; spin < 3; spin++) {
            outCome[spin] = Math.floor((Math.random() * 65) + 1);
            switch (outCome[spin]) {
            case checkRange(outCome[spin], 1, 27):  // 41.5% probability
                betLine[spin] = "blank";
                blanks++;
                break;
            case checkRange(outCome[spin], 28, 37): // 15.4% probability
                betLine[spin] = "Grapes";
                grapes++;
                break;
            case checkRange(outCome[spin], 38, 46): // 13.8% probability
                betLine[spin] = "Banana";
                bananas++;
                break;
            case checkRange(outCome[spin], 47, 54): // 12.3% probability
                betLine[spin] = "Orange";
                oranges++;
                break;
            case checkRange(outCome[spin], 55, 59): //  7.7% probability
                betLine[spin] = "Cherry";
                cherries++;
                break;
            case checkRange(outCome[spin], 60, 62): //  4.6% probability
                betLine[spin] = "Bar";
                bars++;
                break;
            case checkRange(outCome[spin], 63, 64): //  3.1% probability
                betLine[spin] = "Bell";
                bells++;
                break;
            case checkRange(outCome[spin], 65, 65): //  1.5% probability
                betLine[spin] = "Seven";
                sevens++;
                break;
            }
        }
        return betLine;
    }

    /* This function calculates the player's winnings, if any
    function determineWinnings()
    {
        if (blanks == 0)
        {
            if (grapes == 3) {
                winnings = playerBet * 10;
            }
            else if (bananas == 3) {
                winnings = playerBet * 20;
            }
            else if (oranges == 3) {
                winnings = playerBet * 30;
            }
            else if (cherries == 3) {
                winnings = playerBet * 40;
            }
            else if (bars == 3) {
                winnings = playerBet * 50;
            }
            else if (bells == 3) {
                winnings = playerBet * 75;
            }
            else if (sevens == 3) {
                winnings = playerBet * 100;
            }
            else if (grapes == 2) {
                winnings = playerBet * 2;
            }
            else if (bananas == 2) {
                winnings = playerBet * 2;
            }
            else if (oranges == 2) {
                winnings = playerBet * 3;
            }
            else if (cherries == 2) {
                winnings = playerBet * 4;
            }
            else if (bars == 2) {
                winnings = playerBet * 5;
            }
            else if (bells == 2) {
                winnings = playerBet * 10;
            }
            else if (sevens == 2) {
                winnings = playerBet * 20;
            }
            else if (sevens == 1) {
                winnings = playerBet * 5;
            }
            else {
                winnings = playerBet * 1;
            }
            winNumber++;
            showWinMessage();
        }
        else
        {
            lossNumber++;
            showLossMessage();
        }

    }

    /* When the player clicks the spin button the game kicks off
    $("#spinButton").click(function() {
        playerBet = $("div#betEntry>input").val();

        if (playerMoney == 0)
        {
            if (confirm("You ran out of Money! \nDo you want to play again?")) {
                resetAll();
                showPlayerStats();
            }
        }
        else if (playerBet > playerMoney) {
            alert("You don't have enough Money to place that bet.");
        }
        else if (playerBet < 0) {
            alert("All bets must be a positive $ amount.");
        }
        else if (playerBet <= playerMoney) {
            spinResult = Reels();
            fruits = spinResult[0] + " - " + spinResult[1] + " - " + spinResult[2];
            $("div#result>p").text(fruits);
            determineWinnings();
            turn++;
            showPlayerStats();
        }
        else {
            alert("Please enter a valid bet amount");
        }

    });
    */