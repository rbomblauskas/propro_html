# `enigma_html.h` Modulis

`enigma_html.h` modulis suteikia funkcijas, kurios leidžia generuoti HTML turinį C programose. Šis modulis skirtas supaprastinti HTML dokumentų kūrimą, įskaitant lenteles `<table>`, antraštes `<h1>` ir nenumeruojamus sąrašus `<ul>`, taip pat leidžia pritaikyti stilius naudojant CSS klases ir konfigūracijas.

## Modulio funkcijos

### 1. HTML dokumento pradžios ir pabaigos generavimas
- Modulis leidžia lengvai kurti HTML dokumento struktūrą naudojant funkcijas, skirtas HTML dokumento pradžiai ir pabaigai: `html_document_begin`, `html_document_end`.

### 2. Navigacijos juostos generavimas
- `navbar_gen` generuoja navigacijos juostą su logotipu ir nuorodomis pagal `NavbarConfig`.

### 3. Lentelių kūrimas
- Yra funkcijos lentelėms kurti su pritaikomais nustatymais: `table_begin`, `table_end`.
- Palaikomos lentelės antraštės: `table_header`, eilutės: `table_row_begin`, `table_row_end`, ir langeliai: `table_cell`, `table_cell_number`.
- Konfigūruojamos lentelės išvaizdos parinktys, pvz., `striped`, `hoverable`, `bordered` ir `responsive`.

### 4. Antraštės ir `div` elementai
- Palaikomos antraštės kūrimo funkcijos: `h1_gen`.
- Turinio talpinimas į `div` elementus: `div_begin`, `div_end`.

### 5. Sąrašai
- Funkcijos nenumeruojamų sąrašų kūrimui: `list_begin`, `list_end`, `list_item`, su pasirenkamomis CSS klasėmis.

### 6. HTML specialių simbolių užkodavimas
- Funkcija `html_escape` užtikrina, kad HTML specialūs simboliai būtų teisingai užkoduoti, kad išvengtume sintaksės klaidų ir XSS atakų ([plačiau apie XSS](https://lt.wikipedia.org/wiki/XSS)).
