#ifndef INPUT_SMALL_SCALE_D57_H
#define INPUT_SMALL_SCALE_D57_H

//D4T50 instance
#ifdef D4T50

    //Number of periods of the network activity (T)
    const unsigned short T = 50;

    //Maximum demand
    const unsigned short DEMANDA_MAX =  57;

    //Initial node demand and period (i,t)
    const unsigned short source_demanda[57][2] = {
        {75,0},
        {8,1},
        {18,1},
        {35,1},
        {42,1},
        {88,1},
        {11,2},
        {22,2},
        {29,2},
        {38,2},
        {51,2},
        {95,2},
        {2,4},
        {24,4},
        {34,4},
        {38,4},
        {40,4},
        {57,4},
        {71,4},
        {73,4},
        {84,4},
        {49,5},
        {78,5},
        {6,6},
        {97,6},
        {24,7},
        {83,7},
        {46,8},
        {1,9},
        {11,9},
        {20,9},
        {59,9},
        {62,9},
        {70,9},
        {91,9},
        {23,10},
        {27,10},
        {29,10},
        {39,10},
        {47,10},
        {75,10},
        {88,10},
        {53,11},
        {87,11},
        {5,12},
        {10,12},
        {24,12},
        {76,12},
        {92,12},
        {94,12},
        {48,13},
        {68,13},
        {98,13},
        {6,14},
        {30,14},
        {86,14},
        {49,15}           
    };

    //Define shortest paths for all demand nodes
    const unsigned short min_paths[57][100][16] = { 
    {
        {75,61,51,57,0}
    },
    {
        {8,0} 
    },
    {
        {18,5,8,0},
        {18,37,8,0} 
    },
    {
        {35,50,0} 
    },
    {        
        {42,64,8,0}
    },
    {
        {88,50,0},
        {88,57,0} 
    },
    {
        {11,9,64,8,0},
        {11,18,5,8,0},
        {11,18,37,8,0},
        {11,27,5,8,0},
        {11,27,37,8,0},
        {11,27,64,8,0},
        {11,62,5,8,0},
        {11,62,37,8,0},
        {11,62,64,8,0},
        {11,83,5,8,0},
        {11,83,37,8,0},
        {11,83,64,8,0},
        {11,84,64,8,0}
    },
    {
        {22,34,0},
        {22,38,0},
        {22,50,0},
        {22,57,0},
        {22,80,0},
        {22,87,0} 
    },
    {
        {29,32,34,0},
        {29,32,38,0},
        {29,32,50,0},
        {29,32,57,0},
        {29,49,57,0},
        {29,51,57,0},
        {29,65,57,0},
        {29,70,57,0},
        {29,81,57,0},
        {29,90,57,0}
    },
    {
        {38,0}
    },
    {
        {51,57,0} 
    },
    {
        {95,10,35,50,0},
        {95,10,58,50,0},
        {95,10,88,50,0},
        {95,10,88,57,0},
        {95,61,51,57,0},
        {95,82,51,57,0},
        {95,82,70,57,0},
        {95,82,81,57,0},
        {95,82,88,50,0},
        {95,82,88,57,0},
        {95,82,90,57,0},
        {95,85,51,57,0},
        {95,85,81,57,0},
        {95,85,88,50,0},
        {95,85,88,57,0},
        {95,85,90,57,0},
        {95,98,51,57,0},
        {95,98,58,50,0},
        {95,98,81,57,0},
        {95,98,88,50,0},
        {95,98,88,57,0},
        {95,98,90,57,0}
    },
    {
        {2,7,68,49,57,0},
        {2,7,92,49,57,0},
        {2,7,92,70,57,0},
        {2,43,19,32,34,0},
        {2,43,19,32,38,0},
        {2,43,19,32,50,0},
        {2,43,19,32,57,0},
        {2,43,19,49,57,0},
        {2,43,19,51,57,0},
        {2,43,19,65,57,0},
        {2,43,19,70,57,0},
        {2,43,44,17,96,0},
        {2,43,44,30,96,0},
        {2,43,68,49,57,0},
        {2,43,92,49,57,0},
        {2,43,92,70,57,0},
        {2,45,19,32,34,0},
        {2,45,19,32,38,0},
        {2,45,19,32,50,0},
        {2,45,19,32,57,0},
        {2,45,19,49,57,0},
        {2,45,19,51,57,0},
        {2,45,19,65,57,0},
        {2,45,19,70,57,0},
        {2,45,44,17,96,0},
        {2,45,44,30,96,0},
        {2,45,68,49,57,0},
        {2,45,69,15,96,0},
        {2,45,69,26,57,0},
        {2,45,69,26,80,0},
        {2,45,69,32,34,0},
        {2,45,69,32,38,0},
        {2,45,69,32,50,0},
        {2,45,69,32,57,0},
        {2,45,69,49,57,0},
        {2,45,69,65,57,0},
        {2,45,69,70,57,0},
        {2,45,69,86,96,0},
        {2,45,92,49,57,0},
        {2,45,92,70,57,0},
        {2,66,19,32,34,0},
        {2,66,19,32,38,0},
        {2,66,19,32,50,0},
        {2,66,19,32,57,0},
        {2,66,19,49,57,0},
        {2,66,19,51,57,0},
        {2,66,19,65,57,0},
        {2,66,19,70,57,0},
        {2,66,29,32,34,0},
        {2,66,29,32,38,0},
        {2,66,29,32,50,0},
        {2,66,29,32,57,0},
        {2,66,29,49,57,0},
        {2,66,29,51,57,0},
        {2,66,29,65,57,0},
        {2,66,29,70,57,0},
        {2,66,29,81,57,0},
        {2,66,29,90,57,0},
        {2,66,68,49,57,0},
        {2,66,92,49,57,0},
        {2,66,92,70,57,0}
    },
    {
        {24,8,0},
        {24,67,0},
        {24,87,0}
    },
    {
        {34,0}
    },
    {
        {38,0} 
    },
    {
        {40,96,0}
    },
    {  
        {57,0} 
    },
    {
        {71,34,0},
        {71,50,0} 
    },
    {
        {73,58,50,0} 
    },
    {
        {84,64,8,0} 
    },
    {
        {49,57,0}
    },
    {
        {78,13,74,42,64,8,0},
        {78,13,77,28,24,8,0},
        {78,13,77,28,24,67,0},
        {78,13,77,28,24,87,0},
        {78,13,77,28,31,8,0},
        {78,13,77,28,31,67,0},
        {78,13,77,28,31,87,0},
        {78,13,77,28,40,96,0},
        {78,13,91,28,24,8,0},
        {78,13,91,28,24,67,0},
        {78,13,91,28,24,87,0},
        {78,13,91,28,31,8,0},
        {78,13,91,28,31,67,0},
        {78,13,91,28,31,87,0},
        {78,13,91,28,40,96,0},
        {78,14,77,28,24,8,0},
        {78,14,77,28,24,67,0},
        {78,14,77,28,24,87,0},
        {78,14,77,28,31,8,0},
        {78,14,77,28,31,67,0},
        {78,14,77,28,31,87,0},
        {78,14,77,28,40,96,0},
        {78,14,91,28,24,8,0},
        {78,14,91,28,24,67,0},
        {78,14,91,28,24,87,0},
        {78,14,91,28,31,8,0},
        {78,14,91,28,31,67,0},
        {78,14,91,28,31,87,0},
        {78,14,91,28,40,96,0},
        {78,47,74,42,64,8,0},
        {78,47,77,28,24,8,0},
        {78,47,77,28,24,67,0},
        {78,47,77,28,24,87,0},
        {78,47,77,28,31,8,0},
        {78,47,77,28,31,67,0},
        {78,47,77,28,31,87,0},
        {78,47,77,28,40,96,0},
        {78,47,91,28,24,8,0},
        {78,47,91,28,24,67,0},
        {78,47,91,28,24,87,0},
        {78,47,91,28,31,8,0},
        {78,47,91,28,31,67,0},
        {78,47,91,28,31,87,0},
        {78,47,91,28,40,96,0} 
    },
    {
        {6,10,35,50,0},
        {6,10,58,50,0},
        {6,10,88,50,0},
        {6,10,88,57,0},
        {6,73,58,50,0},
        {6,79,35,50,0},
        {6,79,58,50,0},
        {6,79,88,50,0},
        {6,79,88,57,0} 
    },
    {
        {97,28,24,8,0},
        {97,28,24,67,0},
        {97,28,24,87,0},
        {97,28,31,8,0},
        {97,28,31,67,0},
        {97,28,31,87,0},
        {97,28,40,96,0} 
    },
    {
        {24,8,0},
        {24,67,0},
        {24,87,0}
    },
    {
        {83,5,8,0},
        {83,37,8,0},
        {83,64,8,0}
    },
    {
        {46,96,0} 
    },
    {
        {1,44,17,96,0},
        {1,44,30,96,0},
        {1,68,49,57,0},
        {1,92,49,57,0},
        {1,92,70,57,0}
    },
    {
        {11,9,64,8,0},
        {11,18,5,8,0},
        {11,18,37,8,0},
        {11,27,5,8,0},
        {11,27,37,8,0},
        {11,27,64,8,0},
        {11,62,5,8,0},
        {11,62,37,8,0},
        {11,62,64,8,0},
        {11,83,5,8,0},
        {11,83,37,8,0},
        {11,83,64,8,0},
        {11,84,64,8,0} 
    },
    {
        {20,11,9,64,8,0},
        {20,11,18,5,8,0},
        {20,11,18,37,8,0},
        {20,11,27,5,8,0},
        {20,11,27,37,8,0},
        {20,11,27,64,8,0},
        {20,11,62,5,8,0},
        {20,11,62,37,8,0},
        {20,11,62,64,8,0},
        {20,11,83,5,8,0},
        {20,11,83,37,8,0},
        {20,11,83,64,8,0},
        {20,11,84,64,8,0},
        {20,36,9,64,8,0},
        {20,36,27,5,8,0},
        {20,36,27,37,8,0},
        {20,36,27,64,8,0},
        {20,36,84,64,8,0}
    },
    {
        {59,5,8,0},
        {59,35,50,0},
        {59,58,50,0},
        {59,71,34,0},
        {59,71,50,0},
        {59,88,50,0},
        {59,88,57,0}
    },
    {
        {62,5,8,0},
        {62,37,8,0},
        {62,64,8,0} 
    },
    {
        {70,57,0} 
    },
    {
        {91,28,24,8,0},
        {91,28,24,67,0},
        {91,28,24,87,0},
        {91,28,31,8,0},
        {91,28,31,67,0},
        {91,28,31,87,0},
        {91,28,40,96,0}
    },
    {
        {23,66,19,32,34,0},
        {23,66,19,32,38,0},
        {23,66,19,32,50,0},
        {23,66,19,32,57,0},
        {23,66,19,49,57,0},
        {23,66,19,51,57,0},
        {23,66,19,65,57,0},
        {23,66,19,70,57,0},
        {23,66,29,32,34,0},
        {23,66,29,32,38,0},
        {23,66,29,32,50,0},
        {23,66,29,32,57,0},
        {23,66,29,49,57,0},
        {23,66,29,51,57,0},
        {23,66,29,65,57,0},
        {23,66,29,70,57,0},
        {23,66,29,81,57,0},
        {23,66,29,90,57,0},
        {23,66,68,49,57,0},
        {23,66,92,49,57,0},
        {23,66,92,70,57,0},
        {23,75,61,51,57,0}
    },
    {
        {27,5,8,0},
        {27,37,8,0},
        {27,64,8,0} 
    },
    {
        {29,32,34,0},
        {29,32,38,0},
        {29,32,50,0},
        {29,32,57,0},
        {29,49,57,0},
        {29,51,57,0},
        {29,65,57,0},
        {29,70,57,0},
        {29,81,57,0},
        {29,90,57,0} 
    },
    {
        {39,16,40,96,0},
        {39,16,46,96,0},
        {39,25,40,96,0} 
    },
    {
        {47,74,42,64,8,0},
        {47,77,28,24,8,0},
        {47,77,28,24,67,0},
        {47,77,28,24,87,0},
        {47,77,28,31,8,0},
        {47,77,28,31,67,0},
        {47,77,28,31,87,0},
        {47,77,28,40,96,0},
        {47,91,28,24,8,0},
        {47,91,28,24,67,0},
        {47,91,28,24,87,0},
        {47,91,28,31,8,0},
        {47,91,28,31,67,0},
        {47,91,28,31,87,0},
        {47,91,28,40,96,0} 
    },
    {
        {75,61,51,57,0}
    },
    {
        {88,50,0},
        {88,57,0}
    },
    {
        {53,16,40,96,0},
        {53,16,46,96,0} 
    },
    {
        {87,0}
    },
    {
        {5,8,0} 
    },
    {
        {10,35,50,0},
        {10,58,50,0},
        {10,88,50,0},
        {10,88,57,0}
    },
    {
        {24,8,0},
        {24,67,0},
        {24,87,0} 
    },
    {
        {76,14,77,28,24,8,0},
        {76,14,77,28,24,67,0},
        {76,14,77,28,24,87,0},
        {76,14,77,28,31,8,0},
        {76,14,77,28,31,67,0},
        {76,14,77,28,31,87,0},
        {76,14,77,28,40,96,0},
        {76,14,91,28,24,8,0},
        {76,14,91,28,24,67,0},
        {76,14,91,28,24,87,0},
        {76,14,91,28,31,8,0},
        {76,14,91,28,31,67,0},
        {76,14,91,28,31,87,0},
        {76,14,91,28,40,96,0}
    },
    {
        {92,49,57,0},
        {92,70,57,0} 
    },
    {
        {94,1,44,17,96,0},
        {94,1,44,30,96,0},
        {94,1,68,49,57,0},
        {94,1,92,49,57,0},
        {94,1,92,70,57,0},
        {94,7,68,49,57,0},
        {94,7,92,49,57,0},
        {94,7,92,70,57,0},
        {94,43,19,32,34,0},
        {94,43,19,32,38,0},
        {94,43,19,32,50,0},
        {94,43,19,32,57,0},
        {94,43,19,49,57,0},
        {94,43,19,51,57,0},
        {94,43,19,65,57,0},
        {94,43,19,70,57,0},
        {94,43,44,17,96,0},
        {94,43,44,30,96,0},
        {94,43,68,49,57,0},
        {94,43,92,49,57,0},
        {94,43,92,70,57,0}
    },
    {
        {48,67,0},
        {48,80,0},
        {48,87,0},
        {48,96,0}
    },
    {
        {68,49,57,0} 
    },
    {        
        {98,51,57,0},
        {98,58,50,0},
        {98,81,57,0},
        {98,88,50,0},
        {98,88,57,0},
        {98,90,57,0} 
    },
    {
        {6,10,35,50,0},
        {6,10,58,50,0},
        {6,10,88,50,0},
        {6,10,88,57,0},
        {6,73,58,50,0},
        {6,79,35,50,0},
        {6,79,58,50,0},
        {6,79,88,50,0},
        {6,79,88,57,0}
    },
    {
        {30,96,0} 
    },
    {
        {86,96,0} 
    },
    {
        {49,57,0}
    },
    };
    
    //Define the number of shortest paths
    const unsigned short min_paths_size[57] = {1,1,2,1,1,2,13,6,10,1,1,22,61,3,1,1,1,1,2,1,1,1,44,9,7,3,3,1,5,13,18,7,3,1,7,22,3,10,3,15,1,2,2,1,1,4,3,14,2,21,4,1,6,9,1,1,1};
    
    
# endif
#endif /* INPUT_SMALL_SCALE_D57_H */

