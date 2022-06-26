// YUVA & MOKSHITH
    #include<bits/stdc++.h>
    using namespace std;

class student
{
public:

    string name;
    string mailid;
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


student random_student()
{
    student s;
    string temp_string="";
    for(int i=0;i<10;i++)
    {
        char c='a'+rand()%26;
        temp_string+=c;
    }
    s.name = temp_string;
    s.mailid=temp_string;
    s.rollnumber=temp_string;
    s.number = temp_string;

    s.size_of_group = 2 + rand()%4;
    s.introvertism_num = rand()%11;
    s.desi_num = rand()%11;
    s.emotional_num = rand()%11;

    string s0[2];
    s0[0]="Morning Person";
    s0[1]="Night Owl";
    s.MCQ[0]=s0[rand()%2];

    string s1[12];
    s1[0]="Cricket";
    s1[1]="Football";
    s1[2]="Badminton";
    s1[3]="Table Tennis";
    s1[4]="Volleyball";
    s1[5]="Basketball";
    s1[6]="Tennis";
    s1[7]="Hockey";
    s1[8]="Yoga";
    s1[9]="Chess";
    s1[10]="Some other sport not mentioned above";
    s1[11]="I don't play any sport";
    s.MCQ[1]=s1[rand()%12];

    string s2[7];
    s2[0]="Valorant";
    s2[1]="PUBG";
    s2[2]="COD-Mobile";
    s2[3]="CS-GO";
    s2[4]="Fortnight";
    s2[5]="Some specific game not mentioned above";
    s2[6]="Who plays those PC or Mobile games 🤦🏻‍♂️";
    s.MCQ[2]=s2[rand()%7];

    string s3[6];
    s3[0]="Drama";
    s3[1]="Action";
    s3[2]="Horror";
    s3[3]="Comedy";
    s3[4]="Romantic";
    s3[5]="Sci-fi";
    s.MCQ[3]=s3[rand()%6];

    string s4[5];
    s4[0]="Dining - Anjappar";
    s4[1]="Cafe - CCD";
    s4[2]="Park - Watsa";
    s4[3]="Gajendra Circle";
    s4[4]="Place doesn't matter much";
    s.MCQ[4]=s4[rand()%5];

    string s5[2];
    s5[0]="Yes";
    s5[1]="No";
    s.MCQ[5]=s5[rand()%2];

    string s6[7];
    s6[0]="Photography";
    s6[1]="Musical Instrument";
    s6[2]="Singing";
    s6[3]="Literature";
    s6[4]="Fine Arts";
    s6[5]="Dance";
    s6[6]="NONE OF THE ABOVE";
    s.MCQ[6]=s6[rand()%7];

    return s;
}

void print_student(student s)
{
    cout<<s.name<<endl;
    cout<<s.size_of_group<<endl;
    cout<<s.introvertism_num<<endl;
    cout<<s.desi_num<<endl;
    cout<<s.emotional_num<<endl;
    for(int i=0;i<7;i++)
        cout<<s.MCQ[i]<<endl;
}


int32_t main()
{
    int num_students=1000;
    student stud[num_students];

    int x=0;
    ofstream file;
    file.open("input.csv");
    file<<"Timestamp,Username,Your Name,Phone Number,Roll Number ,Size of friends group you prefer to be a part of,On Scale of 1-10 ,how introvert you consider yourself to be,On Scale of 1-10 ,how much you weigh Emotion over Logic,On Scale of 1-10 ,how Desi 😂 you consider yourself to be,Your best part of day to live !,Sport you are interested in ,E-Sport that you are interested in,Movie genre you feel most connected,Hang out spot you prefer,Self improvement is one of the major things I look forward to,Interested  Art\n";

    for(int i=0;i<num_students;i++)
    {
        student temp = random_student();
        //print_student(temp);
        //cout<<endl;
        stud[i]=temp;
        file<<"2022/02/7 12:00:00AM GMT+5:30"<<","<<temp.mailid<<","<<temp.name<<","<<temp.number<<","<<temp.rollnumber<<","<<temp.size_of_group<<","<<temp.introvertism_num<<","<<temp.emotional_num<<","<<temp.desi_num<<","<<temp.MCQ[0]<<","<<temp.MCQ[1]<<","<<temp.MCQ[2]<<","<<temp.MCQ[3]<<","<<temp.MCQ[4]<<","<<temp.MCQ[5]<<","<<temp.MCQ[6]<<"\n";
    }

}
