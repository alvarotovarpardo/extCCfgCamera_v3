import os
import re
from CCfgCamGeneral_properties import separatePrivate
from CCfgCamGeneral_methods import unifyEnums


# función para extraer el contenido de una clase 
# usado para initDefault y config_base
def extractClassParams(init_path, pattern):
    with open(init_path, 'r') as f:
        content = f.read()

    match = re.search(pattern, content, re.DOTALL)
    
    if match:
        return match.group(0)
    else:
        return None


def isolateClasses(input_files):
    # Carpeta con las clases
    raw_folder_location = os.path.join(os.getcwd(), 'bin', 'header', 'build', 'classes_raw')
    os.makedirs(raw_folder_location, exist_ok = True)
    
    
    # Lista de archivos de salida
    output_files = [
        os.path.join(raw_folder_location, 'CCfg_fix.h'),
        os.path.join(raw_folder_location, 'CCfg_distributed.h'),
        os.path.join(raw_folder_location, 'CCfg_analytics.h'),
        os.path.join(raw_folder_location, 'CCfg_lite.h')
    ]

    # Procesar cada archivo de entrada con su archivo de salida correspondiente
    for input_file, output_file in zip(input_files, output_files):
        with open(input_file, 'r', encoding='utf-8') as file:
            lines = file.readlines()
            
        # Localizar la clase CCfgCamGeneral
        inside_class = False
        class_content = []
        for line in lines:
            # Inicia el bloque de la clase
            if 'class CCfgCamGeneral' in line:
                inside_class = True

            if inside_class:
                class_content.append(line)

                # Si se ha alcanzado el final de la clase con el cierre `};`
                if line.startswith('};'):
                    break

        # Escribir el contenido completo de la clase en el archivo de salida
        if inside_class:
            with open(output_file, 'w', encoding='utf-8') as output:
                output.write(''.join(class_content))
        else:
            print(f'No se encontró la clase CCfgCamGeneral en {input_file}.')
        
    print(f"Header classes extracted in {raw_folder_location}")
    
    # Terminamos limpiando las clases 
    separatePrivate()


#################################
#################################
# Leemos los métodos de la clase extraída
# Por ahora sólo dejo los modos público y privado de la clase CCfgCamGeneral en concreto
# Se puede hacer una abstracción mayor e introducir la clase buscada directamente
def readAndCleanClass(input_file, public = True):
    methods = [] # Methods pueden ser métodos o propiedades
    enums = []
    class_pattern = re.compile(r"^class\s+CCfgCamGeneral\s*:\s*public\s+CCfgClass")

    if public:
        # Patrones de búsqueda
        section_pattern = re.compile(r"^\s*public\s*:")
        enum_pattern = re.compile(r"^\s*enum")
        end_pattern = re.compile(r"^\s*private\s*:")
    else:
        section_pattern = re.compile(r"^\s*private\s*:")
        end_pattern = re.compile(r"^\s*};")

    # Flags para ubicarnos
    inside_class = False
    inside_section = False

    with open(input_file, 'r', encoding='utf-8') as file:
        for line in file:
            line = line.strip()
            
            # Verificar si estamos en la clase CCfgCamGeneral
            if class_pattern.match(line):
                inside_class = True
                continue

            # Verificar si estamos en la sección public:
            if inside_class and section_pattern.match(line):
                inside_section = True
                continue

            # Si estamos dentro de la clase y en la sección public:
            if inside_class and inside_section:
                
                # Antes de nada aplicamos limpieza:
                    ############# PUBLIC #################
                if public:
                    if 'STRCPY' in line:
                        line = re.sub('STRCPY','strcpy_s', line)
                    if 'STRNCPY' in line:
                        line = re.sub('STRNCPY', 'strncpy_s', line)
                    if 'Crypt' in line:
                        line = "//" + line
                    if 'QString' in line:
                        line = "//" + line
                    if 'QByte' in line:
                        line = "//" + line
                    if 'CCfgCamGeneral' in line:
                        line = re.sub('CCfgCamGeneral', 'extendedCCfgCamGeneral', line)
                    if 'Jzon' in line:
                        line = "//" + line
                    
                    ############# PRIVATE #################
                if not public:
                    if 'QByte' in line:
                        line = "//" + line
                    if 'STRCPY' in line:
                        line = re.sub('STRCPY','strcpy_s', line)
                    if 'STRNCPY' in line:
                        line = re.sub('STRNCPY', 'strncpy_s', line)
                    if 'Crypt' in line:
                        line = "//" + line
                    if 'QString' in line:
                        line = "//" + line
                # Si encontramos un enum, lo agregamos a la lista de enums
                if public and enum_pattern.match(line):
                    enums.append(line)
                    continue
                
                # Si encontramos el final de la clase, terminamos
                elif end_pattern.match(line):
                    break
                
                # Agregamos los métodos a la lista de methods
                else:
                    methods.append(line)
    
    return methods, enums


#################################
#################################


def classifyContent():

    for isPublic in True, False:
            
        input_folder = os.path.join(os.getcwd(), 'bin', 'header', 'build', 'classes_clean')
        
        if not isPublic:
            output_path = os.path.join(os.getcwd(), 'bin\\header\\private')
            os.makedirs(output_path, exist_ok = True)
            output_file = os.path.join(os.getcwd(), 'bin\\header\\private\\extendedCCfgCamGeneral_properties.h')
            enum_output = os.path.join(output_path, 'enums.txt')
        elif isPublic:
            output_path = os.path.join(os.getcwd(), 'bin\\header\\public')
            os.makedirs(output_path, exist_ok = True)
            output_file = os.path.join(output_path, 'extendedCCfgCamGeneral_methods.h')
            enum_output = os.path.join(output_path, 'enums.txt')
    
        content_fix = []
        content_distributed = []
        content_analytics = []
        content_lite = []
        
        # Fix
    
        fix_file = os.path.join(input_folder, 'CCfg_fix.h')
        if os.path.exists(fix_file):
            content_fix, enum_fix = readAndCleanClass(fix_file, isPublic)
            
            # Copiar el contenido de CCfg_fix.h directamente al archivo unificado
            with open(output_file, 'w', encoding='utf-8') as output:
                for method in content_fix:
                    output.write('\t' + method + '\n')
            with open(enum_output, 'w', encoding='utf-8') as output:
                output.write('\n\t//#################### Fix #######################*/\n\n')
                for enum in enum_fix:
                    output.write(enum + '\n')
    
        else:
            print(f"Fix file {fix_file} does not exist.")
            
             
        # Distributed
        
        # Leer y añadir los métodos de distributed que no están en fix
        flag = 0
        distributed_file = os.path.join(input_folder, 'CCfg_distributed.h')
        if os.path.exists(distributed_file):
            content_distributed, enum_distributed = readAndCleanClass(distributed_file, isPublic)
            with open(output_file, 'a', encoding='utf-8') as output:
                for method in content_distributed:
                    if method not in content_fix:
                        if flag == 0:
                            output.write('\n\t//#################### Distributed #######################*/\n\n')

                            flag = 1
                        output.write('\t' + method + '\n')
            if isPublic:
                with open(enum_output, 'a', encoding='utf-8') as output:
                    output.write('\n\t//#################### Distributed #######################*/\n\n')
                    for enum in enum_distributed:
                        if enum not in enum_fix:
                            output.write(enum + '\n')
        else:
            print(f"Distributed file {distributed_file} does not exist.")
            
            
        # Analytics
        
        # Leer y añadir los métodos de analytics que no están en fix ni en distributed
        flag = 0
        analytics_file = os.path.join(input_folder, 'CCfg_analytics.h')
        if os.path.exists(analytics_file):
            content_analytics, enum_analytics = readAndCleanClass(analytics_file, isPublic)
            with open(output_file, 'a', encoding='utf-8') as output:
                for method in content_analytics:
                    if method not in content_fix and method not in content_distributed:
                        if flag == 0:
                            output.write('\n\t//###################### Analytics ######################*/\n')
                            flag = 1
                        output.write('\t' + method + '\n')
                if isPublic:
                    with open(enum_output, 'a', encoding='utf-8') as output:
                        output.write('\n\t//#################### Analytics #######################*/\n\n')
                        for enum in enum_analytics:
                            if enum not in enum_fix and enum not in enum_distributed:
                                output.write(enum + '\n')
        else:
            print(f"Analytics file {analytics_file} does not exist.")
    
    
        # Lite
        
        # Leer y añadir los métodos de lite que no están en los anteriores
        flag = 0
        lite_file = os.path.join(input_folder, 'CCfg_lite.h')
        if os.path.exists(lite_file):
            content_lite, enum_lite = readAndCleanClass(lite_file, isPublic)
            with open(output_file, 'a', encoding='utf-8') as output:
                for method in content_lite:
                    if method not in content_fix and method not in content_distributed and method not in content_analytics:
                        if flag == 0:
                            output.write('\n\t//###################### Lite ######################\n')
                            flag = 1
                        output.write('\t' + method + '\n')
            if isPublic:
                with open(enum_output, 'a', encoding='utf-8') as output:
                    output.write('\n\t#################### Lite #######################\n\n')
                    for enum in enum_lite:
                        if enum not in enum_fix and enum not in enum_distributed and enum not in enum_analytics:
                            output.write(enum + '\n')
        else:
            print(f"Lite file {lite_file} does not exist.")
                    
        if isPublic:
            Content = 'Methods'
            # Llamamos a la unificación de enums
            unifyEnums()
        else:
            Content = 'Properties'
        print(f"config_camera.h {Content} classified at {output_file}.")    
        
        


# Función para comentar duplicados

def commentDuplicate(private = True):
    if private:
        output_lines = []
        properties = {}  
        
        
        input_file = os.path.join(os.getcwd(), 'bin', 'Header', 'private', 'extendedCCfgCamGeneral_properties.h')
        
        with open(input_file, 'r') as f:
            lines = f.readlines()
        
        property_pattern = re.compile(r'(\w+)\s+m_\w(\w+);')  # Para capturar la propiedad
        
        
        for line in lines:
            # Buscar propiedades
            prop_match = property_pattern.search(line)
            if prop_match:
                prop_type = prop_match.group(1)  # int, double, etc.
                prop_name = prop_match.group(2)  # Nombre de la propiedad sin 'm_'
                
                # Si ya existe una propiedad con el mismo nombre, comentar la línea actual
                if prop_name in properties:
                    print(f"Propiedad duplicada encontrada: {line.strip()}. Comentando...")
                    output_lines.append("// " + line) 
                else:
                    properties[prop_name] = prop_type
                    output_lines.append(line) 
                continue  
        
            # No miramos lo que no buscamos
            output_lines.append(line)
        
        # Reescribimos...
        with open(input_file, 'w') as f:
            f.writelines(output_lines)
        
#%%

##############################################################################
###################### extendedCCfgCamGeneral init!! #########################
##############################################################################
        
# ----------------------------------------------------------------------------------
# Aquí van las funciones de initDefault(), que serán llamadas en create_extCCfgFiles
# ----------------------------------------------------------------------------------



# Copiamos los initDefault de cada SW a un .cpp 
def copyInitParams(init_path):
    files = ['init_fix.cpp',
        'init_distributed.cpp',
        'init_analytics.cpp',
        'init_lite.cpp'
    ]
    
    init_pattern = r'void\s+CCfgCamGeneral::initDefault\(\)\s*{[^}]*}'

    output_paths = [os.path.join(os.path.join(os.getcwd(), 'bin\\cpp\\initDefault\\init_raw'), file) for file in files]
    if not os.path.exists(os.path.join(os.getcwd(), 'bin\\cpp\\initDefault\\init_raw')):
        os.makedirs(os.path.join(os.getcwd(), 'bin\\cpp\\initDefault\\init_raw'))
    for input_path, output_path in zip(init_path, output_paths):
        content = extractClassParams(input_path, init_pattern)
        if content:
            with open(output_path, 'w') as f:
                f.write(content)
        else:
            print(f"No se encontró la función initDefault en {input_path}")
    print(f"initDefault content copied to {output_path}")


# Limpiamos los initDefault y creamos init_clean. Aquí se imponen los filtros sobre qué
# coger, qué no, etc.

# Leemos los parámetros que nos interesen...
def readParametersInit(file):
    with open(file,'r') as f:
        parameters = []
        for line in f:
            stripped_line = line.strip()
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


# ... y con ello creamos el archivo filtrado ...

def classifyInitDefault():
    
    input_folder = os.path.join(os.getcwd(), 'bin', 'cpp', 'initDefault', 'init_raw')
    output_file = os.path.join(os.getcwd(), 'bin', 'cpp', 'initDefault', 'initDefaultContent.cpp')
    content_fix = []
    content_distributed = []
    content_analytics = []
    content_lite = []
    # Contenido del fix
    fix_file = os.path.join(input_folder, 'init_fix.cpp')
    content_fix = readParametersInit(fix_file)
    # Copiar el contenido directamente al archivo unificado
    with open(output_file, 'w', encoding='utf-8') as output:
        for method in content_fix:
            output.write('\t' + method + '\n')
                
    # Leer y añadir los métodos de distributed que no están en fix
    flag = 0
    distributed_file = os.path.join(input_folder, 'init_distributed.cpp')
    content_distributed = readParametersInit(distributed_file)
    with open(output_file, 'a', encoding='utf-8') as output:
        for method in content_distributed:
            if method not in content_fix:
                if flag == 0:
                    output.write('\n\t  //################## Distributed ###################*/\n')
                    flag = 1
                output.write('\t' + method + '\n')
                    

    # Seguimos con analytics
    
    flag = 0
    analytics_file = os.path.join(input_folder, 'init_analytics.cpp')
    content_analytics = readParametersInit(analytics_file)
    with open(output_file, 'a', encoding='utf-8') as output:
        for method in content_analytics:
            if method not in content_fix and method not in content_distributed:
                if flag == 0:
                    output.write('\n\t //#################### Analytics ###################*/\n')
                    flag = 1
                output.write('\t' + method + '\n')

    # Terminamos con Lite
    
    flag = 0
    lite_file = os.path.join(input_folder, 'init_lite.cpp')
    content_lite = readParametersInit(lite_file)
    with open(output_file, 'a', encoding='utf-8') as output:
        for method in content_lite:
            if method not in content_fix and method not in content_distributed and method not in content_analytics:
                if flag == 0:
                    output.write('\t  //###################### Lite ######################*/\n')
                    flag = 1
                output.write('\t' + method + '\n')


    print(f"initDefault() content classified at {output_file}.")


#%%

##############################################################################
######################## config_base modules #################################
##############################################################################
        
# ----------------------------------------------------------------------------------
# Aquí van las funciones de config_base.h, llamadas en create_configBase
# ----------------------------------------------------------------------------------
    

# Leemos y copiamos el configBase de Redlook...
def copyConfigBaseHeader(init_path):
    file = 'config_base.h'
    
    configBase_pattern = r'class\s+CCfgClass\s*{(?:[^{}]*|{[^{}]*})*};'
    
    output_path = os.path.join(os.getcwd(), 'bin', 'header', 'config_base', 'config_base_raw')
    os.makedirs(output_path, exist_ok = True)
    output_file = os.path.join(output_path, file)
    
    configBaseHeader_content = extractClassParams(init_path, configBase_pattern)
    
    if configBaseHeader_content:
        with open(output_file, 'w') as f:
            f.write(configBaseHeader_content)
        print(f'\nconfig_base.h read and copied to {output_path}.\n')
    else:
        print(f'No se encontró config_base.h en {init_path}')
    
    
# ... le ponemos un filtro de contenido ...
def readConfigBaseHeader(file):
    with open(file,'r') as f:
        parameters = []
        for line in f:
            stripped_line = line.strip()
            
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
            if 'Jzon' in stripped_line:
                stripped_line = '//' + stripped_line
            
            
            if stripped_line and stripped_line not in parameters: # Evitamos duplicados
                parameters.append(stripped_line)
    return parameters

# ... y generamos el archivo que sí vamos a incluir en el .h
def classifyConfigBaseHeader():
    
    input_file = os.path.join(os.getcwd(), 'bin', 'header', 'config_base', 'config_base_raw', 'config_base.h')
    output_file = os.path.join(os.getcwd(), 'bin', 'header', 'config_base', 'config_base.h')
    
    configBaseContent = readConfigBaseHeader(input_file)
    # Copiar el contenido directamente al archivo unificado
    with open(output_file, 'w', encoding='utf-8') as output:
        output.write("\n".join(configBaseContent))
    print("config_base.h classified in {output_file}")




                