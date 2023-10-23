//  Zainab Aslam    21I-25575   BSCS-F
//  Design and Analysis of Algorithm
//  Final Project
//  Part 1
//  Strings

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <unordered_map>


using namespace std;
int var = string::npos;

//--------------------------------------------Function to check if the we CanMakeMeal in given nums (0/1)----------------------------

bool CanMakeMeal(vector<string>& group, vector<string>& nums)
{
    unordered_map<string, bool> group_list;
    for (const auto& ingredient : group) {
        group_list[ingredient] = true;
    }

    vector<string> matched_ingredient;

    for (int i = 0; i < nums.size(); i++)
    {
        if (group_list.count(nums[i]))
        {
            bool karp = true;
            for (int j = 1; j < group.size(); j++) {
                int x = i + j;
                if (x >= nums.size() || !group_list.count(nums[x])) {
                    karp = false;
                    break;
                }
            }
            if (karp) {
                int k = 0;
                while (k < group.size()) {
                    matched_ingredient.push_back(nums[i + k]);
                    k++;
                }
                vector<string> new_nums(nums.begin(), nums.end());
                auto iterate = new_nums.begin() + i + group.size();
                new_nums.erase(new_nums.begin() + i, iterate);
                nums = new_nums;
                i = 0;
                continue;
            }
        }
    }

    bool return_result = !matched_ingredient.empty();
    return return_result;
}

   //-----------------------------------------------------Main Function-------------------------------------------------


int main() {

    string str;

    int choice = 0;

    while (choice < 1 || choice > 5)
    {
        cout << "Enter the test case number (1-5): ";
        cin >> choice;
        if (choice < 1 || choice > 5)
        {
            cout << "INVALID CHOICE!!!" << endl;
            cout << "Please enter a valid test case number between 1 and 5." << endl;
        }
    }

    //----------------------------------------Selecting input choice to run the test case------------------------------------

    string test_case_number;

    if (choice == 1)
        test_case_number = "Test case 1";

    else if (choice == 2)
        test_case_number = "Test case 2";

    else if (choice == 3)
        test_case_number = "Test case 3";

    else if (choice == 4)
        test_case_number = "Test case 4";

    else if (choice == 5)
        test_case_number = "Test case 5";

    else
        cout << "Test case choice is invalid." << endl;



    //-------------------------------------------------Reading groups from file--------------------------------------------------

    ifstream file_obj("p1_input.txt");

    vector<vector<string>> read_groups;

    while (getline(file_obj, str))
    {
        int start;
        int end;

        start = str.find('{');

        end = str.find('}', start + (2 - 1));

        while (start != var && end != var)
        {

            string group_ingredient;

            int x = start + (2 - 1);

            int y = end - start - 1;

            group_ingredient = str.substr(x, y);

            vector<string> group;

            int group_start;

            int group_end;

            group_start = group_ingredient.find('\'');

            group_end = group_ingredient.find('\'', group_start + (2 - 1));


            while (group_start != var && group_end != var)
            {
                string temp_ingredient;
                auto rao = group_end - group_start - 1;
                temp_ingredient = group_ingredient.substr(group_start + (2 - 1), rao);
                group.push_back(temp_ingredient);

                //  auto x
                group_start = group_ingredient.find('\'', group_end + (2 - 1));
                group_end = group_ingredient.find('\'', group_start + (2 - 1));
            }
            read_groups.push_back(group);

            start = str.find('{', end + (2 - 1));

            end = str.find('}', start + (2 - 1));
        }
    }
    file_obj.close();



    //----------------------------------------Reading the nums of input choice from file------------------------------------

    file_obj.open("p1_input.txt");

    string ibrahim;

    vector<vector<string>> read_nums;

    while (getline(file_obj, ibrahim)) {

        if (ibrahim.find(test_case_number) != var)
        {

            getline(file_obj, ibrahim);

            int start_;

            int end_;

            start_ = ibrahim.find('[');

            end_ = ibrahim.find(']', start_ + (2 - 1));

            while (start_ != var && end_ != var)
            {
                string test_;

                test_ = ibrahim.substr(start_ + (2 - 1), end_ - start_ - 1);

                vector<string> group;

                int text_start_;

                int text_end_;

                text_start_ = test_.find('\'');

                text_end_ = test_.find('\'', text_start_ + (2 - 1));

                while (text_start_ != var && text_end_ != var)
                {
                    string text;
                    auto x = text_end_ - text_start_ - 1;
                    text = test_.substr(text_start_ + (2 - 1), x);
                    group.push_back(text);
                    text_start_ = test_.find('\'', text_end_ + (2 - 1));
                    text_end_ = test_.find('\'', text_start_ + (2 - 1));
                }
                read_nums.push_back(group);

                start_ = ibrahim.find('[', end_ + (2 - 1));
                end_ = ibrahim.find(']', start_ + (2 - 1));
            }
        }

    }

    file_obj.close(); // close the input file

    //----------------------------------------Calling Function and testing for the test cases--------------------------------------------


    bool flag = false;

    bool display = true;

    for (vector<string>& group : read_groups)
    {
        for (vector<string>& nums : read_nums)
        {

            if (!CanMakeMeal(group, nums))
            {

                display = false;
                flag = true;
                break;
            }
            if (flag)
                break;

        }
    }

    if (display)
    {
        cout << "TRUE!!" << endl;;
        cout << "Test case passed. You can make the meal with the given ingredients :)" << endl;
    }
    else
    {

        cout << "FALSE!!" << endl;;
        cout << "Test case failed. You can not make the meal with the given ingredients :(" << endl;
    }
}
    //-------------------------------------------End of file :) ------------------------------------------------------------------
