#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "Dice.hpp"
#include "Player.hpp"

using namespace std;

// Display the ASCII art title
void display_title() {
    cout << "\n";
    cout << "+--------------------------------------+\n";
    cout << "|                                      |\n";
    cout << "|       *  TWENTY ONE DICE GAME  *     |\n";
    cout << "|                                      |\n";
    cout << "|             .-------.                |\n";
    cout << "|            /   o   /|                |\n";
    cout << "|           .-------. |                |\n";
    cout << "|           | o   o | /                |\n";
    cout << "|           '-------'                  |\n";
    cout << "|                                      |\n";
    cout << "|       ROLL THE DICE. REACH 21!       |\n";
    cout << "|                                      |\n";
    cout << "+--------------------------------------+\n";
    cout << "\n";
    cout << "              MAIN MENU\n";
    cout << "       ---------------------\n";
}
// Read and validate a yes/no answer
char get_yes_no(const string& message) {
    char answer;

    while (true) {
        cout << message;
        cin >> answer;

        if (answer == 'y' || answer == 'Y' ||
            answer == 'n' || answer == 'N') {
            return answer;
        }

        cout << "Invalid input. Please enter y or n.\n";
    }
}

// Read and validate the game mode
int get_game_mode() {
    int choice;

    while (true) {
        cout << "1. Two players\n";
        cout << "2. Play against computer\n";
        cout << "Choose mode (1 or 2): ";

        if (cin >> choice && (choice == 1 || choice == 2)) {
            return choice;
        }

        cout << "Invalid choice. Please enter 1 or 2.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Play one player's turn
void play_turn(Player& player, bool computer) {
    cout << "\n----------------------------------------\n";
    cout << player.get_name() << "'s turn.\n";
    cout << "----------------------------------------\n";

    while (player.get_total_score() < 21) {

        if (!computer) {
            char answer = get_yes_no("Roll the dice? (y/n): ");

            if (answer == 'n' || answer == 'N') {
                cout << player.get_name() << " decides to stop.\n";
                break;
            }
        } else {
            if (player.get_total_score() >= 18) {
                cout << "Computer decides to stop.\n";
                break;
            }

            cout << "Computer is rolling...\n";
        }

        player.take_turn();

        cout << player.get_name()
             << " rolled: " << player.get_value() << "\n";

        cout << "Current score: "
             << player.get_total_score() << "/21\n";

        if (player.get_total_score() > 21) {
            cout << "BUST! " << player.get_name()
                 << " went over 21!\n";
            break;
        }

        if (player.get_total_score() == 21) {
            cout << "EXACTLY 21! Perfect score!\n";
            break;
        }
    }

    cout << player.get_name()
         << " finished with "
         << player.get_total_score()
         << " points.\n";
}

// Display the game points leaderboard
void display_leaderboard(
    const Player& player1,
    const Player& player2,
    int points1,
    int points2
) {
    cout << "\n========== LEADERBOARD ==========\n";
    cout << player1.get_name() << ": " << points1
         << " game points\n";
    cout << player2.get_name() << ": " << points2
         << " game points\n";
    cout << "=================================\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    string name1;
    string name2;

    int points1 = 0;
    int points2 = 0;

    char again = 'y';

    display_title();

    int choice = get_game_mode();

    cout << "\nEnter first player's name: ";
    cin >> name1;

    if (choice == 2) {
        name2 = "Computer";
    } else {
        cout << "Enter second player's name: ";
        cin >> name2;
    }

    Player player1(name1);
    Player player2(name2);

    do {
        cout << "\n========== NEW ROUND ==========\n";

        player1.reset_score();
        player2.reset_score();

        // First player's turn
        play_turn(player1, false);

        // Second player's turn, if the first player has not gone bust
        if (player1.get_total_score() <= 21) {
            play_turn(player2, choice == 2);
        } else {
            cout << player2.get_name()
                 << " wins the round automatically!\n";
        }

        int score1 = player1.get_total_score();
        int score2 = player2.get_total_score();

        cout << "\n========== ROUND RESULTS ==========\n";
        cout << player1.get_name() << ": "
             << score1 << " points\n";
        cout << player2.get_name() << ": "
             << score2 << " points\n";

        // Award game points
        if (score1 == 21 && score2 != 21) {
            points1 += 2;
            cout << player1.get_name()
                 << " earns 2 game points!\n";
        } else if (score2 == 21 && score1 != 21) {
            points2 += 2;
            cout << player2.get_name()
                 << " earns 2 game points!\n";
        } else if (score1 <= 21 && score2 <= 21 &&
                   score1 > score2) {
            points1++;
            cout << player1.get_name() << " wins the round!\n";
        } else if (score2 <= 21 && score1 <= 21 &&
                   score2 > score1) {
            points2++;
            cout << player2.get_name() << " wins the round!\n";
        } else if (score1 == score2) {
            cout << "The round is a tie!\n";
        } else {
            cout << "No points awarded this round.\n";
        }

        display_leaderboard(
            player1, player2, points1, points2
        );

        again = get_yes_no("\nPlay another round? (y/n): ");

    } while (again == 'y' || again == 'Y');

    // Final results
    cout << "\n";
    cout << "========================================\n";
    cout << "             FINAL RESULTS\n";
    cout << "========================================\n";

    cout << player1.get_name() << ": "
         << points1 << " game points\n";

    cout << player2.get_name() << ": "
         << points2 << " game points\n";

    if (points1 > points2) {
        cout << "\nCONGRATULATIONS! "
             << player1.get_name() << " wins the game!\n";
    } else if (points2 > points1) {
        cout << "\nCONGRATULATIONS! "
             << player2.get_name() << " wins the game!\n";
    } else {
        cout << "\nThe game ends in a draw!\n";
    }

    cout << "\n";
    cout << "  _____ _   _    _    _   _ _  __  ____\n";
    cout << " |_   _| | | |  / \\  | \\ | | |/ / / ___|\n";
    cout << "   | | | |_| | / _ \\ |  \\| | ' /  \\___ \\\n";
    cout << "   | | |  _  |/ ___ \\| |\\  | . \\   ___) |\n";
    cout << "   |_| |_| |_/_/   \\_\\_| \\_|_|\\_\\ |____/\n";
    cout << "\n";
    cout << "       THANKS FOR PLAYING!\n";
    cout << "       Twenty One Dice Game\n";
    cout << "\n";

    return 0;
}