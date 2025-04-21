import sys
from pandas import read_csv


if __name__ == '__main__':
    
    with open(sys.argv[2], 'w') as fout:

        print('#pragma once', file=fout)

        data = read_csv(
            sys.argv[1], 
            skiprows=7, 
            sep='\\s+', 
            usecols=['Type', 'Name', 'LBA', 'Length'],
            converters={
                'Name': lambda n: n.removesuffix(';1').replace('.', '_'),
            }
        ).query('Type == "File"')

        data['define'] = '#define'
        data['fileLBA'] = data['Name'].apply(lambda n: f'VS_{n}_LBA')
        data['filelen'] = data['Name'].apply(lambda n: f'VS_{n}_SIZE')
        data['LBA'] = data['LBA'].apply(lambda l: int(l))
        data['Length'] = data['Length'].apply(lambda l: int(l) * 2048)

        data.to_csv(fout, index=False, header=False, sep=' ', columns=['define', 'fileLBA', 'LBA'])
        data.to_csv(fout, index=False, header=False, sep=' ', columns=['define', 'filelen', 'Length'])
