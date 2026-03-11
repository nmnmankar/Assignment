#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool can_attend_all(vector<pair<int, int>> events)
{
    sort(events.begin(), events.end());

    for (int i = 1; i < events.size(); i++)
    {
        if (events[i].first < events[i - 1].second)
        {
            return false;
        }
    }

    return true;
}
int min_rooms_required(vector<pair<int, int>> events)
{
    int n = events.size();

    vector<int> start(n);
    vector<int> end(n);

    for (int i = 0; i < n; i++)
    {
        start[i] = events[i].first;
        end[i] = events[i].second;
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int rooms = 0;
    int max_rooms = 0;

    int i = 0, j = 0;

    while (i < n && j < n)
    {
        if (start[i] < end[j])
        {
            rooms++;
            max_rooms = max(max_rooms, rooms);
            i++;
        }
        else
        {
            rooms--;
            j++;
        }
    }

    return max_rooms;
}

int main()
{
    vector<pair<int, int>> events = {{9, 10}, {9, 12}, {11, 13}, {12, 14}};

    cout << "Can attend all events: ";
    if (can_attend_all(events))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    cout << "Minimum rooms required: ";
    cout << min_rooms_required(events) << endl;
    return 0;
}