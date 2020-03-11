#ifndef INPUT_SMALL_SCALE_D3_H
#define INPUT_SMALL_SCALE_D3_H

//D1T20 instance
#ifdef D1T20

    //Number of periods of the network activity (T)
    const unsigned short T = 20;

    //Maximum demand
    const unsigned short DEMANDA_MAX =  3;

    //Initial node demand and period (i,t)
    const unsigned short source_demanda[3][2] = { 
        {27,0},
        {76,0},
        {15,2}
    };
    
    //Define shortest paths for all demand nodes
    const unsigned short min_paths[3][100][16] = { 
    {
        {27,5, 8, 0},
        {27,37,8, 0},
        {27,64,8, 0}
    },
    {
        {76,14,77,28,24,8, 0},
        {76,14,77,28,24,67,0},
        {76,14,77,28,24,87,0},
        {76,14,77,28,31,8, 0},
        {76,14,77,28,31,67,0},
        {76,14,77,28,31,87,0},
        {76,14,77,28,40,96,0},
        {76,14,91,28,24,8, 0},
        {76,14,91,28,24,67,0},
        {76,14,91,28,24,87,0},
        {76,14,91,28,31,8, 0},
        {76,14,91,28,31,67,0},
        {76,14,91,28,31,87,0},
        {76,14,91,28,40,96,0}
    },
    {
        {15, 96, 0}
    }
    };

    //Define the number of shortest paths
    const unsigned short min_paths_size[3] = {3,14,1};
    
# endif

#endif /* INPUT_SMALL_SCALE_D3_H */

