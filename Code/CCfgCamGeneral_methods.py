import re
import os
from collections import defaultdict


def unifyEnums():
    input_file = os.path.join(os.getcwd(),'bin\\header\\public\\enums.txt')
    output_file = os.path.join(os.getcwd(),'bin\\header\\public\\unified_enums.txt')
    methods_file = os.path.join(os.getcwd(), 'bin\\header\\public\\extendedCCfgCamGeneral_methods.h')
    
    enums = defaultdict(set)

    with open(input_file, 'r') as f:
        text = f.read()

    # Extraer enums del texto
    pattern = re.compile(r'enum (\w+) \{([^}]+)\};')
    matches = pattern.findall(text)
    for enum_name, enum_values in matches:
        values = set(map(str.strip, enum_values.split(',')))
        enums[enum_name].update(values)

    # Escribir enums unificados al archivo de salida
    with open(output_file, 'w') as f:
        for enum_name, values in enums.items():
            f.write(f'\tenum {enum_name} {{ {", ".join(sorted(values))} }};\n')

    print(f'Merged enums written to {output_file}')
    
    with open(methods_file, 'r') as text:
        copy_methods = text.read()
    with open(output_file, 'r') as text:
        copy_enums = text.read()
    with open(methods_file,'w') as text:
        text.write(copy_enums + copy_methods)


    
    