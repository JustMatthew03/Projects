#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <random>

using namespace std;

int score;
int ran;
string capitals[] = { "London", "Paris", "Moscow", "Madrid", "Abu Dhabi", "Accra", "Amsterdam", "Antananarivo", "Athens", "Bankok", "Cairo", "Canberra", "Podgorica", "Damascus", "Dublin", "Hanoi", "Jakarta", "Kabul", "Kingston", "Kyiv" };
string countries[] = { "United Kingdom", "France", "Russia", "Spain", "United Arab Emirates", "Ghana", "Netherlands", "Madagascar", "Greece", "Thailand", "Egypt", "Australia", "Montenegro", "Syria", "Ireland", "Vietnam", "Indonesia", "Afghanistan", "Jamaica", "Ukraine" };

bool isPlaying;
int keyP;

int main()
{
    cout << "Press any key to start. \n";
    while (!_kbhit())
    {
        isPlaying = false;
    }

    isPlaying = true;

    while (isPlaying)
    {
        int max = sizeof(countries) / sizeof(countries[0]);
        ran = rand() % max;

        string ans;
        cout << "What is the capital of " << countries[ran] << "?\n";
        cin >> ans;
        if (ans == capitals[ran])
        {
            score++;
            cout << "That is correct. Score: " << score << ". \n";
        }
        else
        {
            cout << "Incorrect answer! The correct answer was" << capitals[ran] <<"\n";
        }

        if (score >= 5)
        {
            isPlaying = false;
            cout << "You won! \n";
        }
    }
}
