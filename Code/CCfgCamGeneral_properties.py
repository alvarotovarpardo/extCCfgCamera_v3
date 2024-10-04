import re
import os
import shutil

# Función para separar el tipo de dato y las propiedades en líneas separadas
def separateTypeProperties(line):
    # Eliminamos comentarios en línea
    #line = re.sub(r'/\*.*\*/', '', line).strip()
    
    # Limpiamos espacios previos a comas
    line = re.sub(r'\s+,', ',', line)

    # Expresión regular para capturar el tipo de dato y las variables
    pattern = r'(\w[\w\s\*]+)\s+([\w\s,=\[\]\+\(\)]+);'
    match = re.match(pattern, line)

    if match:
        type_data = match.group(1).strip() 
        variables = match.group(2).strip()

        separated_vars = [var.strip() for var in re.split(r'\s*,\s*', variables) if var.strip()]

        separated_lines = [f"{type_data} {var};" for var in separated_vars]

        return separated_lines
    else:
        return [line]  # Si no coincide, devolver la línea original


# Función para copiar las clases y procesar las propiedades privadas
def separatePrivate():
    raw_folder_location = os.path.join(os.getcwd(), 'bin', 'header', 'build', 'classes_raw')
    clean_folder_location = os.path.join(os.getcwd(), 'bin', 'header', 'build', 'classes_clean')
    
    # Crear la carpeta 'classes_clean' si no existe
    if not os.path.exists(clean_folder_location):
        os.makedirs(clean_folder_location)
        print(f"Creando carpeta: {clean_folder_location}")

    # Lista de archivos de entrada y salida
    input_files = [
        os.path.join(raw_folder_location, 'CCfg_fix.h'),
        os.path.join(raw_folder_location, 'CCfg_distributed.h'),
        os.path.join(raw_folder_location, 'CCfg_analytics.h'),
        os.path.join(raw_folder_location, 'CCfg_lite.h')
    ]
    
    output_files = [
        os.path.join(clean_folder_location, 'CCfg_fix.h'),
        os.path.join(clean_folder_location, 'CCfg_distributed.h'),
        os.path.join(clean_folder_location, 'CCfg_analytics.h'),
        os.path.join(clean_folder_location, 'CCfg_lite.h')
    ]
    
    # Copiar los archivos de input a la carpeta de output
    for input_file, output_file in zip(input_files, output_files):
        if os.path.exists(input_file):
            shutil.copy(input_file, output_file)
            print(f"Archivo copiado: {input_file} -> {output_file}")
        else:
            print(f"Archivo no encontrado: {input_file}")
            continue

    # Procesar los archivos en 'classes_clean' para separar las propiedades privadas
    for output_file in output_files:
        inside_private = False
        class_content = []  # Para almacenar todo el contenido de la clase

        # Leer el archivo de salida
        with open(output_file, 'r', encoding='utf-8') as in_file:
            lines = in_file.readlines()

        # Iterar sobre las líneas del archivo
        for line in lines:
            stripped_line = line.strip()

            # Detectar el inicio de la sección private:
            if stripped_line.startswith('private:'):
                inside_private = True
                class_content.append(line)  # Copiar la línea tal cual
                continue

            # Detectar el final de la clase (cuando termina el bloque private)
            if inside_private and stripped_line.startswith('};'):
                inside_private = False
                class_content.append(line)  # Copiar el cierre de la clase tal cual
                continue

            # Si estamos dentro de la sección private:
            if inside_private:
                # Separar las propiedades y agregarlas a la lista de contenido de la clase
                separated_lines = separateTypeProperties(stripped_line)
                class_content.extend([f"    {sep_line}\n" for sep_line in separated_lines])
            else:
                # Agregar el resto de las líneas sin modificaciones
                class_content.append(line)

        # Escribir el contenido completo (clase con propiedades privadas separadas) en el archivo de salida
        with open(output_file, 'w', encoding='utf-8') as out_file:
            out_file.writelines(class_content)



                    
        