[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver MB85RCXX
[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/mb85rcxx/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE) 

Der MB85RCXX ist ein FeRAM-Chip (Ferroelectric Random Access Memory), der die ferroelektrischen und Silizium-Gate-CMOS-Prozesstechnologien zur Herstellung der nichtflüchtigen Speicherzellen nutzt. Im Gegensatz zu SRAM kann der MB85RCXX Daten ohne Datensicherungsbatterie speichern. Die Lese-/Schreib-Lebensdauer der im MB85RCXX verwendeten nichtflüchtigen Speicherzellen wurde auf mindestens 10^12 Zyklen verbessert und übertrifft damit andere nichtflüchtige Speicherprodukte in dieser Anzahl deutlich. Der MB85RCXX benötigt nach dem Schreiben in den Speicher keine Polling-Sequenz wie Flash-Speicher oder E2PROM.

LibDriver MB85RCXX ist der voll funktionsfähige Treiber von MB85RCXX, der von LibDriver gestartet wurde. MB85RCXX bietet Schreib- und Lesefunktionen. LibDriver ist MISRA-konform.

### Inhaltsverzeichnis

  - [Anweisung](#Anweisung)
  - [Installieren](#Installieren)
  - [Nutzung](#Nutzung)
    - [example basic](#example-basic)
  - [Dokument](#Dokument)
  - [Beitrag](#Beitrag)
  - [Lizenz](#Lizenz)
  - [Kontaktieren Sie uns](#Kontaktieren-Sie-uns)

### Anweisung

/src enthält LibDriver MB85RCXX-Quelldateien.

/interface enthält die plattformunabhängige Vorlage LibDriver MB85RCXX IIC.

/test enthält den Testcode des LibDriver MB85RCXX-Treibers und dieser Code kann die erforderliche Funktion des Chips einfach testen.

/example enthält LibDriver MB85RCXX-Beispielcode.

/doc enthält das LibDriver MB85RCXX-Offlinedokument.

/Datenblatt enthält MB85RCXX-Datenblatt.

/project enthält den allgemeinen Beispielcode für Linux- und MCU-Entwicklungsboards. Alle Projekte verwenden das Shell-Skript, um den Treiber zu debuggen, und die detaillierten Anweisungen finden Sie in der README.md jedes Projekts.

/misra enthält die Ergebnisse des LibDriver MISRA Code Scans.

### Installieren

Verweisen Sie auf eine plattformunabhängige IIC-Schnittstellenvorlage und stellen Sie Ihren Plattform-IIC-Treiber fertig.

Fügen Sie das Verzeichnis /src, den Schnittstellentreiber für Ihre Plattform und Ihre eigenen Treiber zu Ihrem Projekt hinzu. Wenn Sie die Standardbeispieltreiber verwenden möchten, fügen Sie das Verzeichnis /example zu Ihrem Projekt hinzu.

### Nutzung

Sie können auf die Beispiele im Verzeichnis /example zurückgreifen, um Ihren eigenen Treiber zu vervollständigen. Wenn Sie die Standardprogrammierbeispiele verwenden möchten, erfahren Sie hier, wie Sie diese verwenden.

#### example basic

```C
#include "driver_mb85rcxx_basic.h"

uint8_t res;
uint8_t data;

res = mb85rcxx_basic_init(MB85RC16, MB85RCXX_ADDRESS_A000);
if (res != 0)
{
    return 1;
}

...

res = mb85rcxx_basic_read(0x00, (uint8_t *)&data, 1);
if (res != 0)
{
    (void)mb85rcxx_basic_deinit();

    return 1;
}
else
{
    mb85rcxx_interface_debug_print("mb85rcxx: 0x%02X.\n", data);
}

...

res = mb85rcxx_basic_write(0x00, (uint8_t *)&data, 1);
if (res != 0)
{
    (void)mb85rcxx_basic_deinit();

    return 1;
}
else
{
    mb85rcxx_interface_debug_print("mb85rcxx: 0x%02X.\n", data);
}

...

(void)mb85rcxx_basic_deinit();

return 0;
```

### Dokument

Online-Dokumente: [https://www.libdriver.com/docs/mb85rcxx/index.html](https://www.libdriver.com/docs/mb85rcxx/index.html).

Offline-Dokumente: /doc/html/index.html.

### Beitrag

Bitte beachten Sie CONTRIBUTING.md.

### Lizenz

Urheberrechte © (c) 2015 - Gegenwart LibDriver Alle Rechte vorbehalten



Die MIT-Lizenz (MIT)



Hiermit wird jeder Person kostenlos die Erlaubnis erteilt, eine Kopie zu erhalten

dieser Software und zugehörigen Dokumentationsdateien (die „Software“) zu behandeln

in der Software ohne Einschränkung, einschließlich, aber nicht beschränkt auf die Rechte

zu verwenden, zu kopieren, zu modifizieren, zusammenzuführen, zu veröffentlichen, zu verteilen, unterzulizenzieren und/oder zu verkaufen

Kopien der Software und Personen, denen die Software gehört, zu gestatten

dazu eingerichtet werden, unter folgenden Bedingungen:



Der obige Urheberrechtshinweis und dieser Genehmigungshinweis müssen in allen enthalten sein

Kopien oder wesentliche Teile der Software.



DIE SOFTWARE WIRD "WIE BESEHEN" BEREITGESTELLT, OHNE JEGLICHE GEWÄHRLEISTUNG, AUSDRÜCKLICH ODER

STILLSCHWEIGEND, EINSCHLIESSLICH, ABER NICHT BESCHRÄNKT AUF DIE GEWÄHRLEISTUNG DER MARKTGÄNGIGKEIT,

EIGNUNG FÜR EINEN BESTIMMTEN ZWECK UND NICHTVERLETZUNG VON RECHTEN DRITTER. IN KEINEM FALL DARF DAS

AUTOREN ODER URHEBERRECHTSINHABER HAFTEN FÜR JEGLICHE ANSPRÜCHE, SCHÄDEN ODER ANDERE

HAFTUNG, OB AUS VERTRAG, DELIKT ODER ANDERWEITIG, ENTSTEHEND AUS,

AUS ODER IM ZUSAMMENHANG MIT DER SOFTWARE ODER DER VERWENDUNG ODER ANDEREN HANDLUNGEN MIT DER

SOFTWARE.

### Kontaktieren Sie uns

Bitte senden Sie eine E-Mail an lishifenging@outlook.com.