import pandas as pd
from math import radians, cos, sin, asin, sqrt

#airports data filtering
airports_header = ['Airport ID','Name', 'City', 'Country', 'Airport IATA', 'ICAO', 'Latitude', 'Longitude', 'Altitude', 'Timezone', 'DST', 'Tz database time zone', 'Type', 'Source']

airports_df = pd.read_csv("dataFiles/airportsData.txt", names = airports_header)

airports_df.drop(airports_df.columns[[0,5,8,9,10,11,12,13]], axis=1, inplace=True)

for x in airports_df.index:
    if len(airports_df.loc[x, "Airport IATA"]) != 3:
        airports_df.drop(x, inplace = True)
        
airports_df.drop_duplicates(inplace = True)

#routes data filtering
routes_header = ['Airline IATA','Airline ID', 'Source airport IATA','Source airport ID', 'Destination airport IATA', 'Destination airport ID', 'Codeshare', 'Stops', 'Equipment']

routes_df = pd.read_csv("dataFiles/routesData.txt", names = routes_header)

routes_df.drop(routes_df.columns[[1,3,5,6,8]], axis=1, inplace=True)

routes_df.drop_duplicates(inplace = True)

#airlines data filtering 
airlines_header = ['Airline ID','Airline Name', 'Alias', 'Airline IATA', 'ICAO', 'Callsign', 'Country', 'Active']

airlines_df = pd.read_csv("dataFiles/airlinesData.txt", names = airlines_header)

airlines_df.drop(airlines_df.columns[[0,2,4,5,6]], axis=1, inplace=True)

#merging the data
merged_routes = pd.merge(routes_df, airlines_df, on ='Airline IATA')
merged_routes.drop_duplicates(inplace = True)


df = merged_routes.copy()

# Calculating distance to each airport
distance = []

for i in range(len(df)):
    start = df.iloc[i,1]
    end = df.iloc[i,2]
    
    start_ind = airports_df.loc[airports_df['Airport IATA'] == start].index.values
    end_ind = airports_df.loc[airports_df['Airport IATA'] == end].index.values
    
    
    if (len(airports_df.loc[start_ind,'Latitude'].values)<=0) or (len(airports_df.loc[end_ind,'Latitude'].values)<=0):
        distance.append('na')
    elif (len(airports_df.loc[start_ind,'Longitude'].values)<=0) or (len(airports_df.loc[end_ind,'Longitude'].values)<=0):
        distance.append('na')
    else:
        start_lat = radians(airports_df.loc[start_ind,'Latitude'].values[0])
        end_lat = radians(airports_df.loc[end_ind,'Latitude'].values[0])
        start_lon = radians(airports_df.loc[start_ind,'Longitude'].values[0])
        end_lon = radians(airports_df.loc[end_ind,'Longitude'].values[0])
        
        dlon = end_lon - start_lon
        dlat = end_lat - start_lat

        a = sin(dlat / 2)**2 + cos(start_lat) * cos(end_lat) * sin(dlon / 2)**2
        c = 2 * asin(sqrt(a))

        distance.append(c*6371)
        
df.drop(df.columns[[3,4,5]], axis=1, inplace=True)

df['Distance'] = distance

for i in df.index:
    if df.loc[i, "Distance"] == 'na':
        df.drop(i, inplace = True)
        
avg_spd = 925
time = []
for i in range(5):
    time.append(df.iloc[i,3]/avg_spd)
    
df2 = df.copy()

# Filtering out USA Data

airs = ['ATL', 'DFW', 'DEN','ORD', 'LAX', 'CLT', 'MCO', 'LAS', 'PHX', 'SEA', 'JFK', 'EWR', 'MSP', 'DTW', 'BOS', 'SLC', 'PHL', 'BWI', 'BNA', 'IAD', 'PDX', 'HNL', 'STL', 'MSY', 'RDU', 'CLE', 'IND', 'CVG', 'MKE', 'ANC', 'BDL', 'OMA', 'BOI', 'CHS', 'OKC']

airsd = []
for i in range(len(df2)):
    start = df2.iloc[i,1]
    end = df2.iloc[i,2]
    if ((start in airs) and (end in airs)):
        
        airsd.append(i)
        
df3 = pd.DataFrame() 

for j in airsd:
        sobj = pd.Series( [df2.iloc[j,0], df2.iloc[j,1], df2.iloc[j,2], df2.iloc[j,3]])
        df3 = df3.append(sobj, ignore_index=True)
        
mod_df = pd.DataFrame(data = df3.values, columns= ['Airline IATA','Source airport IATA','Destination airport IATA','Distance'])


#data to csv
airports_df.to_csv('dataFiles/airports_processed.csv', index=False)
merged_routes.to_csv('dataFiles/routes_processed.csv', index=False)
df.to_csv('dataFiles/distance_data.csv', index=False)
mod_df.to_csv('dataFiles/usadata.csv', index=False)

