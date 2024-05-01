// //بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
 
// //Author: Khalid9029
 
// #include<bits/stdc++.h>
// typedef long long int ll;
// using namespace std;
 
// const int N=1e5;
// const int INF=1e9+10;
// const ll llINF=1e18+10;
// const ll mod=1e9+7;

// ll coin[2000+1][2000+1];
// ll ways(ll k, ll i)
// {
//     cout<<k<<' '<<i<<" IN"<<endl;
//     if(k==0) {
//         cout<<"out k==0"<<endl;
//         return 1;
//     }
//     if(k<0 || i==0)
//     {
//         cout<<"out impossible"<<endl;
//     return 0;
//     }

//     if(coin[k][i]!=-1) {
//     cout<<"Out DP"<<endl;
//     return coin[k][i];}

//     coin[k][i]=0;
//     for(ll j=i/2;j<=i;j++)
//     {
//         ll x=ways(k-j,j-1);
//         ll y=ways(k,j-1);

//         cout<<x<<' '<<k-j<<' '<<j-1<<endl;
//         cout<<y<<' '<<k<<' '<<j-1<<endl;
//         coin[k][i]+=x+y;
//         cout<<k<<" "<<j<<endl;
//         cout<<coin[k][i]<<endl;
//     }
//     cout<<"out "<<k<<' '<<i<< " value="<<coin[k][i]<<endl;
//     return coin[k][i];
// }
 
// int main()
// {
//     //freopen("input.txt", "r", stdin);
//     //freopen("output.txt", "w", stdout);
 
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     ll t;
//     cin>>t;
//     while(t--)
//     {
//         ll n;
//         cin>>n;
//         memset(coin,-1,sizeof(coin));
//         cout<<ways(n,n)<<endl;
//     }
// }



#include <bits/stdc++.h>
using namespace std;

// Function to calculate the subnet mask based on the number of hosts
string calculateSubnetMask(int num_hosts) {
    int host_bits = 0;
    while ((1 << host_bits) - 2 < num_hosts) {
        host_bits++;
    }
    int subnet_bits = 32 - host_bits;
    string subnet_mask = "";
    for (int i = 0; i < subnet_bits; i++) {
        subnet_mask += "1";
    }
    for (int i = 0; i < host_bits; i++) {
        subnet_mask += "0";
    }
    // Format the subnet mask with dots
    return subnet_mask.substr(0+ "." + subnet_mask.substr(8,  + "." + subnet_mask.substr(16, + "." + subnet_mask.substr(24, 8);
}

// Function to create subnetworks and install PCs
void createSubnetworks(string network, int num_networks, int max_hosts_per_network) {
    int subnet_size = 256 / num_networks;
    cout << "Subnet Size: " << subnet_size << endl;
    for (int i = 0; i < num_networks; i++) {
        string subnet_address = network + "." + to_string(i * subnet_size);
        cout << "Subnetwork " << i + 1 << ": " << subnet_address << endl;
        for (int j = 0; j < 2; j++) {
            cout << "PC" << j + 1 << " IP Address: " << subnet_address << "." << j + 1 + (i * subnet_size) << endl;
        }
    }
}

int main() {
    string student_id;
    cout << "Enter the last 3 digits of your student ID: ";
    cin >> student_id;

    string network = "192.168." + student_id;
    int num_networks;
    cout << "Enter the number of subnetworks to create: ";
    cin >> num_networks;

    int max_hosts_per_network;
    cout << "Enter the maximum number of hosts per network: ";
    cin >> max_hosts_per_network;

    cout << "Network: " << network << ".0" << endl;
    string subnet_mask = calculateSubnetMask(max_hosts_per_network);
    cout << "Subnet Mask: " << subnet_mask << endl;

    createSubnetworks(network, num_networks, max_hosts_per_network);

    return 0;
}