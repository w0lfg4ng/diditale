// SLL.H 0.79x        dont worry be happy
//
//   System Link Layer (Header)
//
//==============================================================================
// pointer_type [pointer_to] * [pointer_in] pointer_name [= address];
//
//http://www.smartrtos.com/wordpress/
#ifndef __SLL_H__
#define __SLL_H__

#ifndef __KEIL__
#warning "Este c�digo provavelmente n�o vai funcionar sem o compilador KEIL."
#endif

#ifndef __FUNC_DSPY__
#define __FUNC_DSPY__
#define _VM52_
typedef unsigned char BYTE;          //Cria tipo BYTE que � um  unsigned char  8 bits sem sinal
typedef unsigned int WORD;           //Cria tipo WORD 16 bits sem sinal
typedef unsigned long DWORD;         //Cria tipo DWORD 32 bits sem sinal
typedef bit BOOL;                    //Cria um tipo Booleano falso verdadeiro 0 falso 1 verdadeiro
typedef DWORD COLORDEF;
typedef WORD HANDLE;

#define TRUE 1
#define FALSE 0

#define CLEAR(c) paintscr(c,c,c)      // Limpa a tela gr�fica com um cinza  0 preto 255 branco
#define MENOR(a,b) ((a)<(b)?(a):(b))  // Esta macro retorna o menor valor entre a e b
#define MAIOR(a,b) ((a)>(b)?(a):(b))  // Esta macro retorna o maior valor entre a e b
#define PARE while(1)
 
typedef struct _SYSTEMTIME {        // Estrutura para pegar a hora do windows
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME;

typedef struct _surface {
    char maskplane;
    char shapeplane;
    char backgroudplane;
    struct _surface * ptr;      //3 bytes
} SURFACE, *PSURFACE;

typedef struct _plan {
    DWORD tcolor;            //4
    char dummy;              
    char shapeplan;
    char backgroudplan;
    struct _plan * ptr;      //3 bytes
} PLAN, *PPLAN;

typedef struct _VgaPalette {       // Estrura usada para armazenar componentes de cor
	BYTE    red;             //Verde
	BYTE    grn;             //Vermelho 
	BYTE    blu;             //Azul
} VGA_PALETTE; 

typedef struct TAGcolor {         // Estrura para definir uma cor em algumas fun��o gr�ficas
  BYTE red;
  BYTE grn;
  BYTE blu;
} COLOR, *PCOLOR;


typedef struct TAGpointxy2 {      // Estrura que difine uma coordenada de um ponto
  unsigned char x;
  unsigned char y;               
} POINT2, *PPOINT2;

typedef struct TAGpointxy {      // Estrura que difine uma coordenada de um ponto
  int x;
  int y;               
} POINT, *PPOINT;

#define IDVIRTUALBMP ('C' + 2)

typedef struct TAGvirtualbmp {      
  BYTE id;           //='C' + 2  
  BYTE x;
  BYTE y;        
  BYTE wide;
  BYTE heigh;
  BYTE plane;     //Plano onde est� o BMP, inicia na coordenada 0,0      
} VIRTUALBMP, *PVIRTUALBMP;

typedef struct tagRECT {          //Estrutura que define as coordenadas e dimess�es de ret�ngulo
    BYTE    x;
    BYTE    y;
    BYTE    widh;
    BYTE    heigh;
} RECT, *PRECT;

typedef struct tagRECTA   {       //Estrutura que define as coordenadas e 
    BYTE    widh;                 //dimess�es ret�ngulo e cor de ret�ngulo
    BYTE    heigh;
    BYTE    finner;               // 0 pinta o interior 1 pinta a borda
    COLOR color;                  
} RECTA, *PRECTA;

typedef struct tagRECTX   {       //Estrutura que define as coordenadas dos v�rtices 
    BYTE    x1;                   //de um ret�ngulo
    BYTE    y1;
    BYTE    x2;
    BYTE    y2;
} RECTX, *PRECTX;

typedef struct tagRECTW
{
    BYTE    left;
    BYTE    top;
    BYTE    right;
    BYTE    bottom;
} RECTW,*PRECTW;

typedef struct tagSROTATE   {       //Estrutura que define dados de uma rota��o 
    BYTE    x;                      //coordenadas
    BYTE    y;
    int     angulo;                 //angulo
    COLOR   cor;                    //cor do fundo
    char    * pbbmp;                 //Poteriaro para um arquivo bmp
    char    scale;                   // 0 normal  negativo diminui  positivo almenta   
} SROTATE, *PSROTATE;

typedef struct TAGcircle {        //Estrutura que define as coordenadas, raio e
  unsigned char x;                //cor de um circulo 
  unsigned char y;
  unsigned char radius;
  COLOR color;
} CIRCLE, *PCIRCLE;

typedef struct TAGcirclex {       //Estrutura que define o raio e a cor de circulo
  unsigned char radius;           //
  COLOR color;
} CIRCLEX, *PCIRCLEX;

typedef struct TAGcmatrix {       //Estrura que define uma matriz gr�fica
  char        xdata * matrix;	    // Ponteiro para a matriz
  BYTE        widh;	              // Largura da matriz
  BYTE        heigh;	    // Altura
  BYTE        fpal;               // Carrega ou n�o paleta
  VGA_PALETTE * p;	              // Ponteiro para a paleta de cores
} MATRIX, *PMATRIX;

// structs representing the (PCM) WAVE's heade

typedef struct Riff          //12 bytes
{
  char chunkId[4]; // "RIFF" (assuming char is 8 bits)
  DWORD chunkSize; // (assuming int is 32 bits)  File length minus 8 bytes	
  char format[4]; // "WAVE"
}WAVRIFF;

typedef struct Format    //  24
{
  char chunkId[4]; // "fmt "
  DWORD chunkSize;     //
  WORD format; // assuming short is 16 bits     1 for PCM
  WORD numChannels;         // Number of channels.	
  DWORD sampleRate;         // Sampling rate.		
  DWORD byteRate;           // Average bytes per second.	
  WORD align;               // nchannels * bits / 8	
  WORD bitsPerSample;       // Bits per sample.	
}WAVFORMAT;

typedef struct tgData     //8 bytes
{
  char chunkId[4]; // "data"
  DWORD chunkSize; // length of data
  char wavedata[1];
}WAVDATA;

struct tgWave // Actual structure of a PCM WAVE file
{
   WAVRIFF riffHeader;
   WAVFORMAT formatHeader;
   WAVDATA dataHeader;
};

typedef struct tgWave WAVE;
typedef struct tgWave *PWAVE;

/*
typedef struct {
  WAVFORMAT *formatHeader;
  char slot;
  WAVDATA *dataHeader;
}SWAVE;
*/

typedef struct tgSwave {
  DWORD Size;     //
  DWORD sampleRate;         // Sampling rate.		
  WORD  numChannels;        // Number of channels.	
  WORD  bitsPerSample;      // Bits per sample.
  char  loop;               // loop  - Era slot Para alinhamento
  char  * pdados;  
} SWAVE;

//The MMTIME structure contains timing information for different types of multimedia data.
typedef struct mmtime_tag {  
    DWORD wType; 
    union { 
        DWORD ms; 
        DWORD sample; 
        DWORD cb; 
        DWORD ticks; 
        struct { 
            BYTE hour; 
            BYTE min; 
            BYTE sec; 
            BYTE frame; 
            BYTE fps; 
            BYTE dummy; 
            BYTE pad[2]; 
        } smpte; 
        struct { 
            DWORD songptrpos; 
        } midi; 
    } u; 
} MMTIME,*PMMTIME;

//http://www.fileformat.info/mirror/egff/ch02_02.htm

//extern char code _VgaTable[];
extern VGA_PALETTE code _VgaTable[];


/* types for wType field in MMTIME struct */
#define TIME_MS         0x0001  /* time in milliseconds */
#define TIME_SAMPLES    0x0002  /* number of wave samples */
#define TIME_BYTES      0x0004  /* current byte offset */
#define TIME_SMPTE      0x0008  /* SMPTE time */
#define TIME_MIDI       0x0010  /* MIDI time */
#define TIME_TICKS      0x0020  /* Ticks within MIDI stream */


#define POINTXY(x,y) ((x)*256 + (y))       //Macro transforma coodenada x,y em WORD  x:r6/y:r7
#define GetBValue(rgb)      ((BYTE)(rgb))  //Pega o valor da componente azul de um RGB
#define GetGValue(rgb)      ((BYTE)(((WORD)(rgb)) >> 8)) //Pega o valor da componente verde de um RGB
#define GetRValue(rgb)      ((BYTE)((rgb)>>16))          //Pega o valor da componente vermelha de um RGB
#define RGB(r,g,b)          (((BYTE)(b)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(r))<<16)) //Calcula um RGB a partir das componentes de cor
sbit BUTTON_OK = 0xB0^7;          // bir do Bot�o P3.7 OK na interface do VM
sbit BOK = 0xB0^7;
//	   0 1 2 3  posi��o alinhado a byte
// PC DWORD |B|G|R|N|    litter endian

//	   0 1 2 3  posi��o alinhado a byte
// 8051     |N|R|G|B|    big endian

//COLOR xdata BGRAUND _at_  0xff84;
//obs O MSB vem primeiro BIG ENDIAN

#ifndef null
 #define null (0)
#endif

#define LOWORD(l)           ((WORD)(l))                           //Pega os 16 bits menos significativos de um DWORD
#define HIWORD(l)           ((WORD)(((DWORD)(l) >> 16) & 0xFFFF)) //Pega os 16 bits mais significativos de um DWORD
#define LOBYTE(w)           ((BYTE)(w))                           //Pega os 8 bits menos significativos de um WORD
#define HIBYTE(w)           ((BYTE)(((WORD)(w) >> 8) & 0xFF))     //Pega os 8 bits mais significativos de um WORD

#define CODETEC       (*(WORD xdata *)0xfe00)    // No menos significativo c�digo da tecla pressionada
// Mouse interface
#define MOUSEX        (*(BYTE xdata *)0xfe04)    // Posi��o x = 0..239
#define MOUSEY        (*(BYTE xdata *)0xfe08)    // Posi��o y = 0..127
#define MOUSESTS      (*(WORD xdata *)0xfe0c)    // bit 0 - Bot�o esquerdo Double Click  LBUTTONDBLCLK
                                                 // bit 1 - Bot�o esquerdo Pressionado   LBUTTONDOWN
                                                 // bit 2 - Bot�o esquerdo liberado      LBUTTONUP
                                                 // bit 3 - Bot�o do meio pressioanado   MBUTTONDOWN
                                                 // bit 4 - Bot�o do meio liberado       MBUTTONUP
                                                 // bit 5 - Mouse em movimento           MOUSEMOVE
                                                 // bit 6 - Roda do mouse movendo        MOUSEWHEEL
                                                 // bit 7 - Bot�o direito pressionado    RBUTTONDOWN
                                                 // bit 8 - Bot�o direito liberado       RBUTTONUP
#define LBUTTONDBLCLK  (0x0001)
#define LBUTTONDOWN    (0x0002)
#define LBUTTONUP      (0x0004)
#define MBUTTONDOWN    (0x0008)
#define MBUTTONUP      (0x0010)
#define MOUSEMOVE      (0x0020)
#define MOUSEWHEELM    (0x0040)
#define RBUTTONDOWN    (0x0080)
#define RBUTTONUP      (0x0100)


#define MOUSEINT      (*(WORD xdata *)0xfe10)    // idem ou status bit 15 prioridade
#define MOUSEWHEEL    (*(int xdata *)0xfe14)     // +120 roda pra frente -120 roda pra tr�s

#define VK_CODE0      (*(BYTE xdata *)0xfe18)     // C�digo da tecla virtual
#define VK_CODE1      (*(BYTE xdata *)0xfe19)     // C�digo da tecla virtual
#define VK_CODE2      (*(BYTE xdata *)0xfe1a)     // C�digo da tecla virtual
#define VK_CODE3      (*(BYTE xdata *)0xfe1b)     // C�digo da tecla virtual
#define VK_CODE4      (*(BYTE xdata *)0xfe1c)     // C�digo da tecla virtual
#define VK_CODE5      (*(BYTE xdata *)0xfe1d)     // C�digo da tecla virtual
#define VK_CODE6      (*(BYTE xdata *)0xfe1e)     // C�digo da tecla virtual
#define VK_CODE7      (*(BYTE xdata *)0xfe1f)     // C�digo da tecla virtual
#define VK_CODE8      (*(BYTE xdata *)0xfe20)     // C�digo da tecla virtual
#define VK_CODE9      (*(BYTE xdata *)0xfe21)     // C�digo da tecla virtual
#define VK_CODE10      (*(BYTE xdata *)0xfe22)     // C�digo da tecla virtual
#define VK_CODE11      (*(BYTE xdata *)0xfe23)     // C�digo da tecla virtual
#define VK_CODE12      (*(BYTE xdata *)0xfe24)     // C�digo da tecla virtual
#define VK_CODE13      (*(BYTE xdata *)0xfe25)     // C�digo da tecla virtual
#define VK_CODE14      (*(BYTE xdata *)0xfe26)     // C�digo da tecla virtual
#define VK_CODE15      (*(BYTE xdata *)0xfe27)     // C�digo da tecla virtual
#define VK_CODE16      (*(BYTE xdata *)0xfe28)     // C�digo da tecla virtual
#define VK_CODE17      (*(BYTE xdata *)0xfe29)     // C�digo da tecla virtual
#define VK_CODE18      (*(BYTE xdata *)0xfe2a)     // C�digo da tecla virtual
#define VK_CODE19      (*(BYTE xdata *)0xfe2b)     // C�digo da tecla virtual
#define VK_CODE20      (*(BYTE xdata *)0xfe2c)     // C�digo da tecla virtual
#define VK_CODE21      (*(BYTE xdata *)0xfe2d)     // C�digo da tecla virtual
#define VK_CODE22      (*(BYTE xdata *)0xfe2e)     // C�digo da tecla virtual
#define VK_CODE23      (*(BYTE xdata *)0xfe2f)     // C�digo da tecla virtual
#define VK_CODE24      (*(BYTE xdata *)0xfe30)     // C�digo da tecla virtual
#define VK_CODE25      (*(BYTE xdata *)0xfe31)     // C�digo da tecla virtual
#define VK_CODE26      (*(BYTE xdata *)0xfe32)     // C�digo da tecla virtual
#define VK_CODE27      (*(BYTE xdata *)0xfe33)     // C�digo da tecla virtual
#define VK_CODE28      (*(BYTE xdata *)0xfe34)     // C�digo da tecla virtual
#define VK_CODE29      (*(BYTE xdata *)0xfe35)     // C�digo da tecla virtual
#define VK_CODE30      (*(BYTE xdata *)0xfe36)     // C�digo da tecla virtual
#define VK_CODE31      (*(BYTE xdata *)0xfe37)     // C�digo da tecla virtual
#define TCOLOR         (*(DWORD xdata *)0xfe38)    // c�digo da cor transparente
#define STSSTDOUT      (*(BYTE xdata *)0xfedc)	 // Se 0 saida caracter na tela, se 1 terminal
#define DELAYEND       (*(BYTE xdata *)0xfee0) 
#define CONTMILLIS     (*(DWORD xdata *)0xfee4) 

#define GRPIXMODE0    (*(BYTE xdata *)0xfef0)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE1    (*(BYTE xdata *)0xfef1)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE2    (*(BYTE xdata *)0xfef2)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE3    (*(BYTE xdata *)0xfef3)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE4    (*(BYTE xdata *)0xfef4)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE5    (*(BYTE xdata *)0xfef5)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE6    (*(BYTE xdata *)0xfef6)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE7    (*(BYTE xdata *)0xfef7)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE8    (*(BYTE xdata *)0xfef8)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE9    (*(BYTE xdata *)0xfef9)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE10   (*(BYTE xdata *)0xfefa)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE11   (*(BYTE xdata *)0xfefb)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE12   (*(BYTE xdata *)0xfefc)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE13   (*(BYTE xdata *)0xfefd)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE14   (*(BYTE xdata *)0xfefe)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
#define GRPIXMODE15   (*(BYTE xdata *)0xfeff)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND

#define DATAXRAM      ((void xdata *) 0xff00)    // 128 para o setor lido ou escrito

/* o VM intercepta o acessos a partir desses endere�os  */

#define GRPIXCOLOR    (*(DWORD xdata *)0xff80)   //cor do pixel {N,R,G,B};
#define TXBGCOLOR     (*(DWORD xdata *)0xff84)   //cor do fundo do caracter	      {N,R,G,B};
#define TXCHARCOLOR   (*(DWORD xdata *)0xff88)   //cor do frente do caracter	      {N,R,G,B};
#define GRADP         (*(WORD xdata *)0xff8c)    //pointer da mem�ria grafica	WORD  {N,R,G,B};

#define TXADP         (*(WORD xdata *)0xff90)    //pointer da mem�ria de texto	WORD  {N,R,G,B};
#define WRGRCOM       (*(BYTE xdata *)0xff94)    //Comando de escrita no grafico
#define RDGRCOM       (*(BYTE xdata *)0xff98)    //Leitura do grafico
#define WRTXCOM       (*(BYTE xdata *)0xff9c)    //Comando de escrita no texto Joga caracter ascii com incremento do ADP  08 backspace  0A line feed 0D carriage return
#define WRTTYCOM      (*(BYTE xdata *)0xff9e)    //Comando de escrita no terminal 
#define RDTXCOM       (*(BYTE xdata *)0xffa0)    //Leitura no texto
#define RDTTYCOM      (*(BYTE xdata *)0xffa2)    //Leitura no Terminal
#define RDTXICOM      (*(BYTE xdata *)0xffa4)    //Leitura no texto com incremento do ADP
#define RDGRICOM      (*(BYTE xdata *)0xffa8)    //Leitura do grafico com incremento do ADP
#define WRGRPFIXCOM   (*(BYTE xdata *)0xffac)    //Escrita na memoria gr�fica usando paleta fixa
#define GRDATARD      (*(DWORD xdata *)0xffb0)   // {N,R,G,B}; lido da memoria gr�fica pelo comando RDGRICOM ou RDGRCOM
#define GRTXMODE      (*(BYTE xdata *)0xffb4)    // Seleciona XOR=0 OR=1 AND=2
#define GRPLNSEL      (*(BYTE xdata *)0xffb7)    // Seleciona o plano grafico atual (FRONTPLN ou BACKPLNs)
#define VPLAFORMH     (*(BYTE xdata *)0xffb8)    //Vers�o da plataforma   ex: 0xffB8 = 0 0xffB9=98  => 0.98
#define VPLAFORML     (*(BYTE xdata *)0xffb9)    //Vers�o da plataforma   ex: 0xffB8 = 0 0xffB9=98  => 0.98
#define PLNCPYSEL     (*(BYTE xdata *)0xffba)    //Seleciona qual o plano vai ser copiado por CopyBackPlane
// defines correspondentes ao acesso de arquivos na unidade de disco
#define LSEEK         (*(DWORD xdata *)0xffbc)   // Long com o numero do setor a ser buscado
#define FILECOMM      (*(char xdata *)0xffc0)    // � ativa qdo � feita uma escrita neste endere�o 0=abrir 1= fechar 2=seek_cur 3=seek_end 4=seek_set 5=Ler 6=escrever
#define NUMBYTES      (*(WORD xdata *) 0xffc2)   // N�mero de bytes lidos  (WORD) 2 Bytes
#define PFILENAME     ((char xdata *)0xffc4)     // ponteiro gen�rico para o nome do arquivos a ser aberto (ponteiro)
#define PFILENAMEADDR 0xffc4    // ponteiro gen�rico para o nome do arquivos a ser aberto (ponteiro)
#define FHANDLE       (*(WORD xdata *)0xffc8)    // Manipulador do arquivo (int)
#define BUFFERPTR     ((char xdata *)0xffcc)     // Ponteiro para o buffer de leitura ou escrita R3:R2:R1 3 Bytes
#define BUFFERPTRADDR 0xffcc    // Ponteiro para o buffer de leitura ou escrita R3:R2:R1 3 Bytes
#define CODERROR      (*(char xdata *)0xffcf)    // C�digo de erro  das opera��a de I/O       (char)
// defines correspondente a gera��o de sons
#define BUFLENGTH     (*(DWORD xdata *)0xffd0)   // Comprimento do buffer da placa de som (DWORD)   32 bits   *
#define BUFSOUNDLENGTH BUFLENGTH 
#define BUFTMPPTR     ((char xdata *)0xffd4)     // Ponteiro do buffer tempor�rio (3 bytes) (ponteiro gen�rico) R3:R2:R1
#define BUFTMPSOUNDPTR BUFTMPPTR
#define BUFTMSOUNDPTRADDR 0xffd4                     // Ponteiro do buffer tempor�rio (3 bytes) (ponteiro gen�rico) R3:R2:R1
#define BUFTMPLEN     (*(WORD xdata *)0xffd8)    // Comprimento com em bytes do buffer tempor�rio (WORD) 2 bytes
#define BUFTMPSOUNDLEN BUFTMPLEN 
#define SOUNDCOMM     (*(char xdata *)0xffdb)    // Toca som do buffer (quando � escrito) 0 = Play, 1=Stop, 2 = Pause, 3= Restart, 4 = Close, 5 = Position
#define BITPERSAM     (*(char xdata *)0xffdd)    // formato dos dados do som (8/16) bits      *
#define NUMCHANNELS   (*(char xdata *)0xffde)    // N�mero de canais 1 = Mono 2 =Stereo  (char)     *
#define SNDSTATUS     (*(char xdata *)0xffdf)    // status d�s comandos e player
#define SAMPLERATE    (*(WORD xdata *)0xffe0)    // Taxa de amostragem  (WORD) 2 bytes  8.0 kHz, 11.025 kHz, 22.05 kHz, and 44.1 kHz.      *
#define SOUNDFREQ     (*(float xdata *)0xffe4)   // Freq so som a ser gerado (float)      Usando na gera��o de tons
#define COUNT10MS     (*(BYTE xdata *)0xffe8)    // Incrementado a cada 10ms
#define COUNT100MS    (*(BYTE xdata *)0xffe9)    // Incrementado a cada 100ms
#define MMTIMESPTR    ((MMTIME xdata *) 0xffec)  // Ponteiro da estrutura mmtime 3 bytes
#define HANDLESND     (*(char xdata *)0xfff0)    // Cont�m o indetificador do som valores entre 0 e 9
#define PPSYSTEMTIME   ((SYSTEMTIME xdata *) 0xfff1)  // Ponteiro para estrutura de dados do rel�gio do windows 3 bytes
#define VALYEAR       (*(WORD xdata *) 0xfff4)   //Ano
#define VALMONTH      (*(BYTE xdata *) 0xfff6)   //Mes 
#define VALDAYOFWEEK  (*(BYTE xdata *) 0xfff7)   //Dia da semana
#define VALDAY        (*(BYTE xdata *) 0xfff8)   //Dia do mes
#define VALHOUR       (*(BYTE xdata *) 0xfff9)   //Hora 24 horas
#define VALMINUTE     (*(BYTE xdata *) 0xfffa)   //Minutos
#define VALSECOND     (*(BYTE xdata *) 0xfffb)   //Segundo
#define VALMILLISECONDS (*(WORD xdata *) 0xfffc) //milisegundos
#define CLOCKCOMM     (*(char xdata *) 0xfffe)   //Comandos do rel�gio  READ e WRITE
#define CPUCOMM	  (*(char xdata *) 0xffff)       //Comandos para a cpu
#define VGATABLE      (_VgaTable)                //Ponteiro da paleta de cores VGA padr�o 

//#define SOUNDLOAD     (*(char xdata *)0xffda)  // Comando de carga dos bytes do buffer tempor�rio para o buffer de som
//#define BUFSRESET     (*(char xdata *)0xffdc)  // Reseta buffer   (quando � escrito)
//#define GRPIXMODE0    (*(BYTE xdata *)0xffb5)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND
//#define GRPIXMODE1    (*(BYTE xdata *)0xffb6)    // Seleciona como o pixel vai ser atualizado, O=sem opera��o, 1=OR com antigo , 2=AND

enum {PLAY,STOP,PAUSE,RESTART,CLOSE,POSITION,STATUS,PLAYTONE,RESETBUF,LOADBUF}; // Comandos do SOUNDCOMM
enum {SNDERROR=255,SNDSUCCESS = 0,SNDBFULL,PLAYING,STOPED,PAUSED};  // estatus do som
enum {FCREATE=1,FOPENRO,FOPEN,FCLOSE,FSEEK_CUR,FSEEK_END,FSEEK_SET,FREAD,FWRITE};
enum {MODEXOR,LESSOPR=0,MODEOR,MODEAND};
enum {MODECOPY,MODECOPYOR,MODECOPYAND};
enum {FRONTPLN,BACKPLN,BACKPLN1=1,BACKPLN2,BACKPLN3,BACKPLN4,
      BACKPLN5,BACKPLN6,BACKPLN7,BACKPLN8,BACKPLN9,BACKPLN10,
      BACKPLN11,BACKPLN12,BACKPLN13,BACKPLN14,BACKPLN15};
// C�digos de erro das opera��es de I/O
//      Constant  Value	System Error Message	Value
#define E2BIG	  7      //Argument list too long	7
#define EACCES	  13   //Permission denied	13
#define EAGAIN	  11   //No more processes or not enough memory or maximum nesting level reached	11
#define EBADF	  9    //Bad file number	9
#define ECHILD	  10   //No spawned processes	10
#define EDEADLOCK     36   //Resource deadlock would occur	36
#define EDOM	  33   //Math argument	33
#define EEXIST	  17   //File exists	17
#define EINVAL	  22   //Invalid argument	22
#define EMFILE	  24   //Too many open files	24
#define ENOENT	  2    //No such file or directory	2
#define ENOEXEC	  8    //Exec format error	8
#define ENOMEM	  12   //Not enough memory	12
#define ENOSPC	  28   //No space left on device	28
#define ERANGE	  34   //Result too large	34  (*) usado
#define EXDEV	  18   //Cross-device link	18
#define EOFILE        6    //Final do arquivo 6
#define FILESUCCESS    0
//*****************************************************************
// Header das fun��es do VM
//----------------------------------------------------------------
extern void          gotoxy      (char x,char y);       //Define coordenada na tela de texto x:0-29, y:0-15
extern void          printchar   (char);                //Imrime um caratere
extern void          prints      (char *);              //Imprime uma strig
extern void          paintscr    (unsigned char r,unsigned char g,unsigned char b);   //Pinta a tela gr�fica com uma cor
extern void          settxadp    (int);                                               //Determina um endere�o na mem�ria de texto 
extern void          setgradp    (int);                                               //Determina um endere�o na mem�ria gr�fica
extern void          clrscr      (unsigned char r,unsigned char g,unsigned char b);   //Pinta fundo de texto com uma cor
extern void          printbmp     (unsigned char col, unsigned char lin, char *);     //Imprime um Bitmap int(R6:R7) char(R5) type(R3) pointer(R2:R1)
extern bit           rdkey       (char data * tecla);                                 //s� para teste n�o use!
extern bit           wrkey       (char);                                              //s� para teste n�o use!
bit                  kbhit(void);                                                     //Retorna 1 se uma tecla foi pressionada 0 se n�o
bit                  _initkey    (void);                                              //Inicializa interface de teclado, Obsoleta
extern bit           rdkeyboard   (char *);                                           //Ler o c�digo de tecla pressionada
extern void          plotxy(unsigned char x,unsigned char y,PCOLOR);                  //Plota um ponto de cor na tecla gr�fica usando um estrutura de cor
extern void          pplotxy(unsigned char x,unsigned char y,DWORD *);                //Plota um ponto de cor na tecla gr�fica RGB
extern WORD          btow(BYTE y,BYTE x);                                             //Transforma uma coordenada x,y em WORD saida = x * 256 + y   
extern BYTE          function_sys(BYTE);
extern void          scroll(char mov);                                                //Scroll tela de texto UPMOVE,DOWNMOVE
extern void          scrollg(char mov,char rol);                                      //Scroll tela gr�fica UPMOVE,DOWNMOVE, LEFTMOVE,RIGHTMOVE  ROTATE,SHIFT}
extern void          moveto(unsigned char x,unsigned char y);                         //Determina coordenada inicial de uma linha
extern void          lineto(unsigned char x,unsigned char y,PCOLOR);                  //Desenha um linha a partir da coordenada inicial at� x,y com uma cor
extern void          drawcircle(PCIRCLE);                                             //Desenha um circulo com dos dados da estrutra CIRCLE
extern void          drawcirclex(unsigned char x,unsigned char y,PCIRCLEX);           //Desenha um circulo nas coordenadas x,y com dos dados da estrutra CIRCLEX
extern void          drawdiscus(PCIRCLE);                                             //Desenha um disco com dos dados da estrutra CIRCLE
extern void          drawdiscusx(unsigned char x,unsigned char y,PCIRCLEX);           //Desenha um disco nas coordenadas x,y com dos dados da estrutra CIRCLEX
extern void          drawrecta(unsigned char x,unsigned char y,PRECTA);
extern void          version(char *,int len);                                                 //Pega a vers�o do SLL ponterio para string com a vers�o 5 bytes s�o necess�rios
extern WORD          xendian16(WORD);                                                 //permuta de big endiam para litter endiam 16 bits
extern DWORD         xendian32(DWORD);                                                //permuta de big endiam para litter endiam 32 bits
extern float         xendianf(float);                                                //permuta de big endiam para litter endiam 32 bits
extern void          CopyBackPlane(void);                                             //Copia todo conte�do do plano de fundo (PLNCPYSEL) para o plano frontal
extern void          CopyBackPlaneEx(char plane);                                     //Copia todo conte�do de um plano de fundo para o plano frontal
extern void          CopyInterPlane(char dest,char src);                              //Copia o conteudo de um plano em outro
extern void          Surfaces(PSURFACE);                                              // Une as superficies e exibe no placo frontal
extern void          CopyRect(PRECT);                                                 //Copia um ret�ngulo do plano de fundo para o plano frontal 
extern void          CopyRectX(PRECTX);                                               //Copia um ret�ngulo do plano de fundo para o plano frontal 
extern void          mplotxy(WORD POINt,BYTE cor,PMATRIX);
extern void          CopyMatrix(unsigned char x,unsigned char y,PMATRIX);             //Copia uma matriz para um dos planos
extern void          BmpToMatrix(MATRIX xdata * mvetor, WORD POINt, char * nomebmp);  //Copia um bitmap para uma matriz
extern void          BmpRotateToMatrix(MATRIX xdata * mvetor, int ang, char * nomebmp);  //Copia um bitmap para uma matriz gerando no �ngulo ang 0-360 graus
extern void          RotateBmp(PSROTATE prot);                                        // Gira um bmp e imprime na tela 
extern bit           PtInRect(BYTE x, BYTE y,PRECT);                                  //Ver se o mouse est� sobre um ret�ngulo
extern bit           vkeydown(BYTE cod);                                              //Ver se uma tecla est� pressionada (entre com o c�digo virtual da tecla vide sll.h)
extern void          yield(char);                                                     // Ceder o tempo a outra terefa
extern WAVDATA *     SearchData(const char *s);                                       // Retorna o poteiro para estrutuda de dados do WAV
extern void          VMOff(void);                                                     //Fecha o VM
extern void          VMReinit(void);                                                  //Reinicializa VM
extern void          PaintPlane (char plane,char cor);                                //Pinta plano de preto at� branco passando por 256 n�veis
extern void          PaintPlan (DWORD);                                //Pinta plano o plano selecionado
extern void          strtoscr(char *);              //Imprime uma strig
extern void          GetSystemTime( SYSTEMTIME *);
extern void          fflush(void);

/* Para todas as fun��es de arquivo a vari�vel CODERROR cont�m o c�digo de erro */
extern WORD          OpenFile(char * fname,char mode );               //Retorna zero se falhou, ou um handle para o arquivo
extern void          SetHandle(int handle); 
extern WORD          ReadFile(WORD handle,WORD nbytes,char * buf);    //Retorna n�mero de bytes lidos, zero se falhou ou fim de arquivo
extern WORD          WriteFile(WORD handle,WORD nbytes,char * buf);   //Retorna n�mero de bytes escritos, zero se falhou
extern long          SeekFile(DWORD indice,char *mode);               //Retorna posi��o relativa ao in�cio do arquivo -1 � falha
extern int           CloseFile (WORD handle);                         //-1 � Falha 
extern int           EraseFile (char *path);                          //-1 � falha

extern char          PlayWaveFile(char mode, char * filename);        // mode loop = 1/once=0 Obs: pode ser um ponteiro para um nome de arquivo ou um vetor contebdo um wav
extern char          LoadWaveFile(char * filename);  // Obs: pode ser um ponteiro para um nome de arquivo ou um vetor contebdo um wav
extern char          PlaySound(char handle); 
extern char          PlayWave(char mode,SWAVE *wave);      // mode = loop = 1/once= 0
extern char          PositionSound(char handle, MMTIME *mmt);
extern char          PropertySound(char hf,WAVFORMAT * wf);
extern char          StatusSound(char handle);
extern void          PauseSound(char handle);
extern void          StopSound(char handle);
extern void          ContinueSound(char handle);
extern char          CloseSound(char handle);
extern void          JoinPlans(PPLAN);

extern void          delay(DWORD n);                      //N tem
extern DWORD         millis(void);                        //70
extern void          delayBreak(void);                    //71

extern void          setstdout(char);                     //N tem | op��es (SCREEN/TERMINAL) defaul SCREEN
extern void          setbaudrate(DWORD clk, WORD * taxa); //73
extern bit           writecomm(BYTE c);                   //74
extern bit           readcomm(BYTE * c);                  //75

extern void          printTTY(char c);                    //66
extern void          printsTTY(char* p);                  //67
extern bit           getcharTTY(char* c);                 //68

enum {UPMOVE,DOWNMOVE, LEFTMOVE,RIGHTMOVE};
enum {SHIFT,ROTATE};
enum {PALNLOAD,PALLOAD};
enum {BGBLACK,BGWHITE=255};
enum {ONCE,LOOPING};
enum {SCREEN,TERMINAL,COMSERIAL,RESERV};
// Extrutura de cabe�alho de arquivo bitmap

struct PALSBITMAP {
    BYTE rgbblue;	//db	?	;intesidade do azul
    BYTE rgbgree;	//db	?	;intesidade do verde
    BYTE rgbred;	//db	?	;intesidade do vermelho
    BYTE regrese;	//db	?	;sempre zero
};


struct SBITMAP {
  
  WORD  bmftype;    //dw        4d42h     ;assinatura 42 4D
  DWORD bmfsize;    //dd        2358      ;tamanho do arquivo em bytes
  WORD  bmfrese1;   //dw        0         ;reservado
  WORD  bmfrese2;   //dw        0         ;reservado
  DWORD bmfoffb;    //dd        1078      ;deslocamento do inicio ateh os dados do bitmap

  DWORD bmisize;    //dd        40        ;Numero de bytes do cabecario de informacao
  DWORD bmiwidh;    //dd        40        ;Largura do bitmat em pixel
  DWORD bmiheigh;   //dd        32        ;Altura do bitmap em pixel
  WORD  bmiplane;   //dw        1         ;Numero de planos 1 (um)
  WORD  bmicount;   //dw        8         ;Numero de bit por pixel  1,4,8,24
  DWORD bmicompr;   //dd        0         ;Tipo de compressao  0 , 1 , 2  ; 0 sem comp.
  DWORD bmsizeim;   //dd        1280      ;Numero de bytes da imagem
  DWORD bmiXmete;   //dd        3790      ;Pixel por metro do dispositivo de saida X
  DWORD bmiYmete;   //dd        3800      ;pixel por metro do dispositivo de saida Y
  DWORD bmclruse;   //dd        256       ;Numero de cores utilizadas na tabela do bitmap
  DWORD bmclrimp;   //dd        256       ;Numero de cores importantes da tabela 

  struct PALSBITMAP palette;
  struct {
    BYTE rgbblue;	//db	?	;intesidade do azul
    BYTE rgbgree;	//db	?	;intesidade do verde
    BYTE rgbred;	//db	?	;intesidade do vermelho
    BYTE regrese;	//db	?	;sempre zero
  }paleta2;
  //BYTE dummy[255*4]; //	db	255 dup( 4 dup(?))

  //BYTE cores[1];	//DB	1280 dup(?)		 user32
};

struct SSMALLBMP {  //big endian
  BYTE type;        //0 'B' ,'C' , 
  BYTE wide;        //1
  BYTE heigh;       //2
  WORD len;         //3
  WORD start_data;  //5
  BYTE bitcor;      //7   1, 4, 8, 24, 32 se bit 7 = 1 n�o compactado        
  BYTE palette[3];  //8   pode 2, 16, 256 , nenhuma
};

/*
struct SSMALLBMP32 {  //big endian
  BYTE type;        // ,'C' 
  BYTE wide;
  BYTE heigh;
  WORD len;
  WORD dummy;
  BYTE bitcor;      // 32,  bit 7 = 1 n�o compactado        
  BYTE pixels[32];  // 2 bits
};
*

extern  char xdata _temp_buf_sprintf[100];


/*
 * Virtual Keys, Standard Set
 */
#define VK_LBUTTON        0x01
#define VK_RBUTTON        0x02
#define VK_CANCEL         0x03
#define VK_MBUTTON        0x04    /* NOT contiguous with L & RBUTTON */

#define VK_BACK           0x08
#define VK_TAB            0x09

#define VK_CLEAR          0x0C
#define VK_RETURN         0x0D

#define VK_SHIFT          0x10
#define VK_CONTROL        0x11
#define VK_MENU           0x12
#define VK_PAUSE          0x13
#define VK_CAPITAL        0x14


#define VK_ESCAPE         0x1B

#define VK_SPACE          0x20
#define VK_PRIOR          0x21
#define VK_NEXT           0x22
#define VK_END            0x23
#define VK_HOME           0x24
#define VK_LEFT           0x25
#define VK_UP             0x26
#define VK_RIGHT          0x27
#define VK_DOWN           0x28
#define VK_SELECT         0x29
#define VK_PRINT          0x2A
#define VK_EXECUTE        0x2B
#define VK_SNAPSHOT       0x2C
#define VK_INSERT         0x2D
#define VK_DELETE         0x2E
#define VK_HELP           0x2F

/* VK_0 thru VK_9 are the same as ASCII '0' thru '9' (0x30 - 0x39) */
/* VK_A thru VK_Z are the same as ASCII 'A' thru 'Z' (0x41 - 0x5A) */

#define VK_LWIN           0x5B
#define VK_RWIN           0x5C
#define VK_APPS           0x5D

#define VK_NUMPAD0        0x60
#define VK_NUMPAD1        0x61
#define VK_NUMPAD2        0x62
#define VK_NUMPAD3        0x63
#define VK_NUMPAD4        0x64
#define VK_NUMPAD5        0x65
#define VK_NUMPAD6        0x66
#define VK_NUMPAD7        0x67
#define VK_NUMPAD8        0x68
#define VK_NUMPAD9        0x69
#define VK_MULTIPLY       0x6A
#define VK_ADD            0x6B
#define VK_SEPARATOR      0x6C
#define VK_SUBTRACT       0x6D
#define VK_DECIMAL        0x6E
#define VK_DIVIDE         0x6F
#define VK_F1             0x70
#define VK_F2             0x71
#define VK_F3             0x72
#define VK_F4             0x73
#define VK_F5             0x74
#define VK_F6             0x75
#define VK_F7             0x76
#define VK_F8             0x77
#define VK_F9             0x78
#define VK_F10            0x79
#define VK_F11            0x7A
#define VK_F12            0x7B
#define VK_F13            0x7C
#define VK_F14            0x7D
#define VK_F15            0x7E
#define VK_F16            0x7F
#define VK_F17            0x80
#define VK_F18            0x81
#define VK_F19            0x82
#define VK_F20            0x83
#define VK_F21            0x84
#define VK_F22            0x85
#define VK_F23            0x86
#define VK_F24            0x87

#define VK_NUMLOCK        0x90
#define VK_SCROLL         0x91

/*
 * VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
 * Used only as parameters to GetAsyncKeyState() and GetKeyState().
 * No other API or message will distinguish left and right keys in this way.
 */
#define VK_LSHIFT         0xA0
#define VK_RSHIFT         0xA1
#define VK_LCONTROL       0xA2
#define VK_RCONTROL       0xA3
#define VK_LMENU          0xA4
#define VK_RMENU          0xA5


#endif
#endif

