import os
import re

def extractInitParams(init_path):
    with open(init_path, 'r') as f:
        content = f.read()

    # Expresión regular para capturar el contenido de la función initDefault
    pattern = r'void\s+CCfgCamGeneral::initDefault\(\)\s*{[^}]*}'
    match = re.search(pattern, content, re.DOTALL)
    
    if match:
        return match.group(0)
    else:
        return None


# Copiamos los initDefault de cada SW a un .txt 
def copyInitParams(init_path):
    files = ['init_fix.txt',
        'init_distributed.txt',
        'init_analytics.txt',
        'init_lite.txt'
    ]
    output_paths = [os.path.join(os.path.join(os.getcwd(), 'bin\\cpp\\initDefault\\init_raw'), file) for file in files]
    if not os.path.exists(os.path.join(os.getcwd(), 'bin\\cpp\\initDefault\\init_raw')):
        os.makedirs(os.path.join(os.getcwd(), 'bin\\cpp\\initDefault\\init_raw'))
    for input_path, output_path in zip(init_path, output_paths):
        content = extractInitParams(input_path)
        if content:
            with open(output_path, 'w') as f:
                f.write(content)
            print(f"Contenido copiado a {output_path}")
        else:
            print(f"No se encontró la función initDefault en {input_path}")




# Función para leer parámetros .txt
def readParameters(file):
    with open(file,'r') as f:
        parameters = []
        for line in f:
            stripped_line = line.strip()
            print(stripped_line)
            if (stripped_line.startswith("//") or
                stripped_line.startswith("/*") or
                stripped_line.endswith("*/") or
                stripped_line.startswith("void") or
                stripped_line.startswith("}") or
                stripped_line.startswith("{")
                ): continue
            
            if 'STRCPY' in stripped_line:
                stripped_line = re.sub('STRCPY', 'strcpy_s', stripped_line)
            if 'STRNCPY' in stripped_line:
                stripped_line = re.sub('STRNCPY', 'strncpy_s', stripped_line)
            if 'Crypt' in stripped_line:
                stripped_line = '//' + stripped_line
            if 'QByte' in stripped_line:
                stripped_line = '//' + stripped_line
            if 'QString' in stripped_line:
                stripped_line = '//' + stripped_line
            
            if stripped_line and stripped_line not in parameters: # Evitamos duplicados
                parameters.append(stripped_line)
    return parameters





