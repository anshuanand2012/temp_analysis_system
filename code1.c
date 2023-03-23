/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

typedef struct{
    int station_no;
    float sky_view;
    float vdr;
    int population_density;
    float fdf;
    float isf;
    int urban;
    int temp[30];
    int distance[5];
    int max_temp;
    int relative_humidity;
    int heat_degree_day;
    int nearest_station;
    int thermally_confotable_days[30];
    int vdr_order;
    int list_date[30];
    int average_temp;
    int nearest_station_urban;
    int heat_island_intensity;
}data;

int main()
{
    int i,j;
    int sum=0;
    FILE *file;
	
	file = fopen("file.txt","r");
	
	if(file == NULL){
		printf("error");
		return 1;
	}
	
	data station[100];
	
	int read = 0;
	int records=0;
	
	do{
		read = fscanf(file,"%d, %f, %f, %d, %f, %f, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d",
					&station[records].station_no,
					&station[records].sky_view,
					&station[records].vdr,
					&station[records].population_density,
					&station[records].fdf,
					&station[records].isf,
					&station[records].urban,
					&station[records].max_temp,
					&station[records].relative_humidity,
					&station[records].temp[0],
					&station[records].temp[1],
					&station[records].temp[2],
					&station[records].temp[3],
					&station[records].temp[4],
					&station[records].temp[5],
					&station[records].temp[6],
					&station[records].temp[7],
					&station[records].temp[8],
					&station[records].temp[9],
					&station[records].temp[10],
					&station[records].temp[11],
					&station[records].temp[12],
					&station[records].temp[13],
					&station[records].temp[14],
					&station[records].temp[15],
					&station[records].temp[16],
					&station[records].temp[17],
					&station[records].temp[18],
					&station[records].temp[19],
					&station[records].temp[20],
					&station[records].temp[21],
					&station[records].temp[22],
					&station[records].temp[23],
					&station[records].temp[24],
					&station[records].temp[25],
					&station[records].temp[26],
					&station[records].temp[27],
					&station[records].temp[28],
					&station[records].temp[29],
					&station[records].distance[0],
					&station[records].distance[1],
					&station[records].distance[2],
					&station[records].distance[3],
					&station[records].distance[4]);
					
					
		if(read == 44){records++;}
		if(read != 44 && !feof(file)){
			printf("error format");
// 			break;
		}
	}while(!feof(file));
	
	if(ferror(file)){
		printf("error reading file");
		return 1;
	}
	
	fclose(file);
	
	//1//
	
	for(i=0;i<5;i++){
	    station[i].heat_degree_day=0;
	}
	
	int average_city_temp;
	
	for(i=0;i<records;i++){
	    for(j=0;j<30;j++){
	        sum=sum+station[i].temp[j];
	    }
	}
	
	average_city_temp=sum/(records*30);
	
    printf("average_city_temp is :%d",average_city_temp);
    
    for(i=0;i<5;i++){
        for(j=0;j<30;j++){
            if(station[i].temp[j]<average_city_temp){
                station[i].heat_degree_day++;
            }
        }
    }
    int max=station[0].heat_degree_day;
    int label=0;
    for(i=0;i<5;i++){
        if(station[i].heat_degree_day>max){
            max=station[i].heat_degree_day;
            label=i;
        }
        
        
    }
    printf("\nstation with highetst heat_degree_day is : station no. %d",label+1);
    
    //2//
    
    int min=10000;
    
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(station[i].distance[j]!=0){
                if(station[j].urban!=1){
        if(station[i].distance[j]<min){
            min=station[i].distance[j];
            station[i].nearest_station=station[j].station_no;
        }}}}
        min=10000;
    }
    
  
    
//   printf("\n%d\n",station[1].nearest_station);
   
   int k=0;
   
   for(i=0;i<5;i++){
       for(j=0;j<30;j++){
           if(station[i].urban==1){
               if(station[i].temp[j]>station[station[i].nearest_station].temp[j]){
                   station[i].thermally_confotable_days[k]=j+1;
                   k++;
               }
           }
       }
   }
   printf("\nfirst 5 thermally_confotable_days of station 2 are: ");
   for(i=0;i<5;i++){
       printf("%d ",station[1].thermally_confotable_days[i]);
   }
    
    //3//
    
    int arr_vdr[5];
    int a;
    k=0;
    for (i = 0; i < 5; ++i) 
        {
            for (j = i + 1; j < 5; ++j) 
            {
                if (station[i].vdr < station[j].vdr) 
                {
                    a = station[i].vdr;
                    station[i].vdr = station[j].vdr;
                    station[j].vdr = a;
                    arr_vdr[k]=j;
                    ++k;
                }
            }
        }
        printf("\n");
    for(i=0;i<5;i++){
        printf("%d ",arr_vdr[i]);
    }
    k=0;
    for(i=0;i<5;i++){
        for(j=0;j<30;j++){
            if(station[i].temp[j]>average_city_temp){
                station[i].list_date[k]=j+1;
                k++;
            }
        }
        k=0;
    }
    printf("\n\n");
    for(i=0;i<4;i++){
        printf("\nstation %d:",station[arr_vdr[i]].station_no);
        for(j=0;j<30;j++){
            printf(" %d",station[arr_vdr[i]].list_date[j]);
        }
    }
    printf("\nstation 1:");
    for(j=0;j<30;j++){
        printf( " %d",station[1].list_date[j]);
    }
    
    //4//
    printf("\n\n\n");
    int arr_population[5];
    
  
    
    k=0;
    for (i = 0; i < 5; ++i) 
        {
            for (j = i+1; j < 5; ++j) 
            {
                if (station[i].population_density > station[j].population_density) 
                {
                    a = station[i].population_density;
                    station[i].population_density = station[j].population_density;
                    station[j].population_density = a;
                    arr_population[k]=station[j].station_no;
                    ++k;
                }
            }
        }
        
    for(i=0;i<5;i++){
        printf("%d ",arr_population[i]);
    }
    int numbers;
    printf("enter number of stations you want to list");
    scanf("%d",&numbers);
    
    for(i=0;i<numbers;i++){
        printf("\nstation no. have population_density %d and max temperture %d.",station[arr_population[i]].population_density,station[arr_population[i]].max_temp);
    }
    
    //5
    int avg_sum=0;
    for(i=0;i<5;i++){
        for(j=0;j<30;j++){
            avg_sum=avg_sum+station[i].temp[j];
        }
        station[i].average_temp=avg_sum/30;
        avg_sum=0;
    }
    
    for(i=0;i<5;i++){
        if(station[i].urban==1){
        station[i].heat_island_intensity=station[station[i].nearest_station_urban].average_temp-station[station[i].nearest_station].average_temp;
        printf("\nstation %d heat_island_intensity: %d",station[i].station_no,station[i].heat_island_intensity);}
    }
    
    
    return 0;
}