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

    int introvertism_num;
    int emotional_num;
    int desi_num;

    string MCQ[7];
};

int find_on_scale(int x,int y)
{
    double ans=abs(x-y);
    ans=sqrt(ans);
    ans++;
    ans=15/ans;
    return ans;
}

int find_score(student x,student y)
{
    // SCORING SYSTEM AND WEIGHTAGE
    int score=0;
    if(x.MCQ[0]==y.MCQ[0])score+=7;
    if(x.MCQ[1]==y.MCQ[1])
    {
        score+=10;
        if(x.MCQ[1]=="K")score-=4;
    }
    if(x.MCQ[2]==y.MCQ[2])
    {
        score+=8;
        if(x.MCQ[2]=="G")score+=2;
    }
    if(x.MCQ[3]==y.MCQ[3])score+=7;
    if(x.MCQ[4]==y.MCQ[4])score+=7;
    if(x.MCQ[5]==y.MCQ[5])score+=15;
    if(x.MCQ[6]==y.MCQ[6])score+=9;

    score+=find_on_scale(x.introvertism_num,y.introvertism_num);
    score+=find_on_scale(x.emotional_num,y.emotional_num);
    score+=find_on_scale(x.desi_num,y.desi_num);
    
    return score;
}

bool compare_group_2(pair<int,pair<student,student>> p1,pair<int,pair<student,student>> p2)
{
    return p1.first<p2.first;
}

bool comparator(pair<int,vector<student>> v1,pair<int,vector<student>> v2){
    return v1.first<v2.first;
}

int mix_2_pairs(pair<student,student> p,pair<student,student> q)
{
    int ans=0;
    ans+=find_score(p.first,q.first);
    ans+=find_score(p.first,q.second);
    ans+=find_score(p.second,q.first);
    ans+=find_score(p.second,q.second);

    return ans;
}

vector<int> check_group2(vector<vector<int>> graph,int num_stud)
{
    int degree[num_stud];
    bool paired[num_stud]={false};
    vector<int> pairs;
    for(int i=0;i<num_stud;i++)
    {
        degree[i]=graph[i].size();
    }

    set<pair<int,int>> s;

    for(int i=0;i<num_stud;i++)
    {
        s.insert({degree[i],i});
    }

    while(!s.empty())
    {
        // if there is no vertex to map with then not possible
        auto itr = s.begin();
        if(itr->first<=0){
            vector<int> v;
            //returning empty vector as we failed to pair students with this graph 
            return v;
        }
        
        // vertex with minimum degree
        auto top = s.begin();
        int vertex = top->second;
        paired[top->second]=true;

        int adjecent = -1;
        
        // finding minimum vertex adjecent to top with min degree
        for(int i=0;i<graph[top->second].size();i++)
        {
            if(paired[graph[top->second][i]])continue;
            if(adjecent==-1)
            {
                adjecent = graph[top->second][i];
            }
            else 
            {
                if(degree[graph[top->second][i]]<degree[adjecent])
                    adjecent = graph[top->second][i];
            }
        }

        // removing them from top and adjecent from set
        paired[adjecent]=true;
        //pushing paired students into pairs vector
        pairs.push_back(top->second);
        pairs.push_back(adjecent);
        s.erase(itr);
        s.erase({degree[adjecent],adjecent});

        // decreacing the degree
        for(int i=0;i<graph[vertex].size();i++)
        {
            if(paired[graph[vertex][i]])continue;
            int v=graph[vertex][i];
            s.erase({degree[v],v});
            degree[v]--;
            s.insert({degree[v],v});
        }

        //decreasing the degree
        for(int i=0;i<graph[adjecent].size();i++)
        {
            if(paired[graph[adjecent][i]])continue;
            int v=graph[adjecent][i];
            s.erase({degree[v],v});
            degree[v]--;
            s.insert({degree[v],v});
        }
    }
    
    // all are paired by now
    return pairs;
}

vector <student> group_of_2(vector <student> group)
{
    // ALGO FOR 2
    // PROBLEM 3

    int num_stud = group.size();
    student odd;
    if(group.size()%2==1){
        //to take care of odd no. of students case
        num_stud--;
    }

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

    vector<vector<int>> graph(num_stud);

    for(int i=0;i<num_stud/2-1;i++)
    {
        int x=score_edge[i].second.first;
        int y=score_edge[i].second.second;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> pairs;
    int min_required_edges=num_stud/2-1;

    for(;min_required_edges<score_edge.size();min_required_edges++)
    {
        int i=min_required_edges;
        int x=score_edge[i].second.first;
        int y=score_edge[i].second.second;

        graph[x].push_back(y);
        graph[y].push_back(x);
        
        pairs=check_group2(graph,num_stud);
        if(pairs.size()==num_stud)break;
    }
    if(group.size()%2==1){
        //if group size waas odd ,add last student .
       pairs.push_back(group.size()-1);
    }
    
    vector <student> group_2;

    for(int x:pairs){
        group_2.push_back(group[x]);
    }

    return group_2;

}

double variance(int x,int y,int z)
{
    // variance with respect to avg
    double avg=double((x+y+z)/3);
    double ans = (x-avg)*(x-avg) + (y-avg)*(y-avg) + (z-avg)*(z-avg);
    ans = ans/3;
    ans = sqrt(ans);
    ans = ans / (avg+0.1);

    return ans;
}

vector <student> group_of_3(vector <student> group)
{
    int num_stud=group.size();
    vector<student> remaining;
    while(num_stud%3!=0)
    {
        num_stud--;
        remaining.push_back(group[num_stud]);
        group.pop_back();
    }

    int score[num_stud][num_stud];
    for(int i=0;i<num_stud;i++)
    {
        for(int j=0;j<num_stud;j++)
        {
            score[i][j]=find_score(group[i],group[j]);
        }
    }

    vector <pair<int,int>> score_index;
    // first = net_score
    // second = its index

    for(int i=0;i<num_stud;i++)
    {
        int net_score=0;
        for(int j=0;j<num_stud;j++)
        {
            net_score+=score[i][j];
        }

        score_index.push_back({net_score,i});
    }

    sort(score_index.begin(),score_index.end());

    bool paired[num_stud]={false}; // is already paired or not
    
    vector<student> final_group;

    for(int i=0;i<num_stud;i++)
    {
        int index=score_index[i].second;
        if(paired[index])continue;
        paired[index]=true;

        int x=-1,y=-1;
        double min_variance;

        for(int j=i+1;j<num_stud;j++)
        {
            index=score_index[j].second;
            if(paired[index])continue;
            for(int k=j+1;k<num_stud;k++)
            {
                index=score_index[k].second;
                if(paired[index])continue;

                if(x==-1)
                {
                    x=score_index[j].second;
                    y=score_index[k].second;
                    index=score_index[i].second;
                    min_variance = variance(score[index][x],score[index][y],score[x][y]);
                }
                else
                {
                    index=score_index[i].second;
                    if(min_variance > variance(score[index][score_index[j].second],score[index][score_index[k].second],score[score_index[j].second][score_index[k].second]))
                    {
                        x=score_index[j].second;
                        y=score_index[k].second;
                        index=score_index[i].second;
                        min_variance = variance(score[index][x],score[index][y],score[x][y]);
                    }
                }
            }
        }

        paired[x]=true;
        paired[y]=true;
        index=score_index[i].second;

        final_group.push_back(group[index]);
        final_group.push_back(group[x]);
        final_group.push_back(group[y]);
    }

    for(int i=0;i<remaining.size();i++)
    {
        final_group.push_back(remaining[i]);
    }

    return final_group;
}

vector <student> group_of_4(vector <student> group)
{
    int num_stud=group.size();
    vector<student> remaining;
    while(num_stud%4!=0)
    {
        num_stud--;
        remaining.push_back(group[num_stud]);
        group.pop_back();
    }

    //grouped a pairs
    group = group_of_2(group);

    //paired as pairs<>
    vector < pair<int,pair<student,student>> > group2;
    for(int i=0;i<num_stud;i+=2)
    {
        int score = find_score(group[i],group[i+1]);
        group2.push_back({score,{group[i],group[i+1]}});
    }

    // sorted according to there similarities 
    sort(group2.begin(),group2.end(),compare_group_2);

    // least similar is grouped with there best pair
    vector<student> final_group;
    bool paired[num_stud/2]={false};

    for(int i=0;i<num_stud/2;i++)
    {
        if(paired[i])continue;
        paired[i]=true;

        int index=-1;
        int max_match;

        for(int j=i+1;j<num_stud/2;j++)
        {
            if(paired[j])continue;
            if(index==-1)
            {
                index=j;
                max_match=mix_2_pairs(group2[i].second,group2[j].second);
            }
            else if(max_match<mix_2_pairs(group2[i].second,group2[j].second)) 
            {
                max_match = mix_2_pairs(group2[i].second,group2[j].second);
                index=j;
            }
        }

        paired[index]=true;
        final_group.push_back(group2[i].second.first);
        final_group.push_back(group2[i].second.second);
        final_group.push_back(group2[index].second.first);
        final_group.push_back(group2[index].second.second);
    }

    for(int i=0;i<remaining.size();i++)
    {
        final_group.push_back(remaining[i]);
    }

    return final_group;
}

vector <student> group_of_5(vector <student> group)
{
    int num_stud=group.size();
    vector<student> remaining;
    while(num_stud%5!=0)
    {
        num_stud--;
        remaining.push_back(group[num_stud]);
        group.pop_back();
    }

    vector<student> pairs1,pairs2,single;
    //splitting into groups of 2/5,2/5 and 1/5 respectively;
    for(int i=0;i<num_stud;i++){
        if(i<2*num_stud/5){
            pairs1.push_back(group[i]);continue;
        }
        if(i<4*num_stud/5){
            pairs2.push_back(group[i]);continue;
        }
        single.push_back(group[i]);
    }

    pairs1= group_of_2(pairs1);
    pairs2= group_of_2(pairs2);
    vector <pair<int,vector<student>>> score_pairs2;

    for(int i=0;i<pairs2.size();i+=2){
        vector <student> v;
        v.push_back(pairs2[i]);
        v.push_back(pairs2[i+1]);
        score_pairs2.push_back({find_score(pairs2[i],pairs2[i+1]),v});
    }
    //sorting according to scores in pairs2
    sort(score_pairs2.begin(),score_pairs2.end(),comparator);
    
    bool paired[single.size()]={false};
    vector <pair<int,vector<student>>> score_combined;
    //assigning singles to sorted pairs2
    for(int i=0;i<score_pairs2.size();i++){
        student x=score_pairs2[i].second[0],y=score_pairs2[i].second[1],z;
        vector <student> v;
        int max=-1,index=-1;
        for(int j=0;j<single.size();j++){
            if(paired[j])continue;
                if(max==-1)
                {   
                    index=j;
                    z=single[j];
                    max = find_score(single[j],x)+find_score(single[j],y);
                }
                else
                {
                    if(max<find_score(single[j],x)+find_score(single[j],y)){
                        index=j;
                        z=single[j];
                        max = find_score(single[j],x)+find_score(single[j],y);
                    }
                }
        }
        //pushing x,y,z in order of their net_score
        int q1=find_score(x,y)+find_score(x,z);
        int q2=find_score(y,x)+find_score(y,z);
        int q3=find_score(z,y)+find_score(z,x);
        if(q1<=q2&&q1<=q3){
            v.push_back(x);
            v.push_back(y);
            v.push_back(z);
            score_combined.push_back({q1,v});
        }
        if(q2<=q1&&q2<=q3){
            v.push_back(y);
            v.push_back(x);
            v.push_back(z);
            score_combined.push_back({q2,v});
        }
        if(q3<=q1&&q3<=q2){
            v.push_back(z);
            v.push_back(y);
            v.push_back(x);
            score_combined.push_back({q3,v});
        }
        paired[index]=true;
    }
    //score_combined contains groups of 3
    //And their first member is the person with least net_score
    sort(score_combined.begin(),score_combined.end(),comparator);

    vector <student> final_group;//final_group=score_combined+pairs1;
    paired[pairs1.size()]={false};
    //assigning pairs1 to least net_score memmbers from score_combined
    for(int i=0;i<score_combined.size();i++){
        student x,y,z=score_combined[i].second[0];
        int max=-1,index=-1;
        for(int j=0;j<pairs1.size();j+=2){
            if(paired[j])continue;
                if(max==-1)
                {   
                    index=j;
                    x=pairs1[j];
                    y=pairs1[j+1];
                    max = find_score(z,pairs1[j])+find_score(z,pairs1[j+1]);
                }
                else
                {
                    if(max<find_score(z,pairs1[j])+find_score(z,pairs1[j+1])){
                        index=j;
                        x=pairs1[j];
                        y=pairs1[j+1];
                        max = find_score(z,pairs1[j])+find_score(z,pairs1[j+1]);
                    }
                }
        }
        final_group.push_back(score_combined[i].second[0]);
        final_group.push_back(score_combined[i].second[1]);
        final_group.push_back(score_combined[i].second[2]);
        final_group.push_back(x);
        final_group.push_back(y);
        paired[index]=true;
    }
    //pushing remaining ones
    for(int i=0;i<remaining.size();i++)
    {
        final_group.push_back(remaining[i]);
    }
    return final_group;
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
