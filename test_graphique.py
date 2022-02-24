import pandas as pd

df = pd.read_excel (r'../data/communes.xlsx')
print (df.iat[3,2])

print (df.iat[3,2]+1)
print (df.iat[3,2]/2)
