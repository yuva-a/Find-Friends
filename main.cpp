// YUVA & MOKSHITH
    #include<bits/stdc++.h>
    using namespace std;

class student
{
public:
    
    string name;
    string number;
    string rollnumber;

    int size_of_group; // 2 - 5

    // Factors to be considered HERE
    // PROBLEM 4
};

int find_score(student x,student y)
{
    // SCORING SYSTEM AND WEIGHTAGE

    return 0;
}

bool check_group2(vector<vector<int>> graph,int num_stud)
{
    return true;
}

vector <student> group_of_2(vector <student> group)
{
    // ALGO FOR 2
    // PROBLEM 3

    int num_stud = group.size();
    vector<vector<int>> graph(num_stud);

    int score[num_stud][num_stud];
    for(int i=0;i<num_stud;i++)
    {
        for(int j=0;j<num_stud;j++)
        {
            score[i][j]=find_score(group[i],group[j]);
        }
    }
    
    // score , (x,y) -> x,y are vectices
    vector < pair< int,pair<int,int> > > score_edge;

    for(int i=0;i<num_stud;i++)
    {
        for(int j=i+1;j<num_stud;j++)
        {
            score_edge.push_back({score[i][j],{i,j}});
        }
    }
    
    sort(score_edge.begin(),score_edge.end());
    reverse(score_edge.begin(),score_edge.end());

    vector< vector<int> > graph(num_stud);

    for(int i=0;i<num_stud/2;i++)
    {
        int x=score_edge[i].second.first;
        int y=score_edge[i].second.second;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int min_required_edges=num_stud/2;

    for(;min_required_edges<score_edge.size();min_required_edges++)
    {
        int i=min_required_edges;
        int x=score_edge[i].second.first;
        int y=score_edge[i].second.second;

        graph[x].push_back(y);
        graph[y].push_back(x);

        if(check_group2(graph,num_stud))break;
    }
}

vector <student> group_of_3(vector <student> group)
{
    // ALGO FOR 3
    // PROBLEM 3
}

vector <student> group_of_4(vector <student> group)
{
    // ALGO FOR 4
    // PROBLEM 3
}

vector <student> group_of_5(vector <student> group)
{
    // ALGO FOR 5
    // PROBLEM 3
}


int32_t main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int num_students=1000;
    student stud[num_students];

    // Take input from CSS FILE 
    // PROBLEM 2

    vector <student> group2;
    vector <student> group3;
    vector <student> group4;
    vector <student> group5;

    for(int i=0;i<num_students;i++)
    {
        if(stud[i].size_of_group == 2)
            group2.push_back(stud[i]);
        if(stud[i].size_of_group == 3)
            group3.push_back(stud[i]);
        if(stud[i].size_of_group == 4)
            group4.push_back(stud[i]);
        if(stud[i].size_of_group == 5)
            group5.push_back(stud[i]);
    }

    group2 = group_of_2(group2);
    group3 = group_of_3(group3);
    group4 = group_of_4(group4);
    group5 = group_of_5(group5);
}
