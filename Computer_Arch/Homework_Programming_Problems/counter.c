// Paul Habjanetz A00579084
// Project Four - Cycles Counter
// 10/30/2014
// CS3339
//

#include <stdlib.h>
#include <stdio.h>

#define MEMSIZE 1048576

static int little_endian, icount, *instruction;
static int mem[MEMSIZE / 4];

static int Convert(unsigned int x)
{
  return (x >> 24) | ((x >> 8) & 0xff00) | ((x << 8) & 0xff0000) | (x << 24);
}

static int Fetch(int pc)
{
  pc = (pc - 0x00400000) >> 2;
  if ((unsigned)pc >= icount) {
    fprintf(stderr, "instruction fetch out of range\n");
    exit(-1);
  }
  return instruction[pc];
}

static int LoadWord(int addr)
{
  if (addr & 3 != 0) {
    fprintf(stderr, "unaligned data access\n");
    exit(-1);
  }
  addr -= 0x10000000;
  if ((unsigned)addr >= MEMSIZE) {
    fprintf(stderr, "data access out of range\n");
    exit(-1);
  }
  return mem[addr / 4];
}

static void StoreWord(int data, int addr)
{
  if (addr & 3 != 0) {
    fprintf(stderr, "unaligned data access\n");
    exit(-1);
  }
  addr -= 0x10000000;
  if ((unsigned)addr >= MEMSIZE) {
    fprintf(stderr, "data access out of range\n");
    exit(-1);
  }
  mem[addr / 4] = data;
}


// call a function for each source to which you pass the source register number as well as the latest stage where this input is needed. you pass it the stage = stage. and the readyStage =


static void isReady(int pipelineStage, int *readyStage)
{
	int i = 0;
	int x = 7;  // MIGHT NEED TO BE 5 *****8
    
	for (i; i < 8; ++i)  // less than the number of stages
	{
        // if the value of the location (1-8) is >= 0 then,
        
        if((readyStage[i] - 1) >= 0)
            readyStage[i] = (readyStage[i] - 1);
        
		else
			readyStage[i] = 0;
	}
    
    
	for (x; x >= 0; --x)
		readyStage[x + 1] = readyStage[x];
	
	readyStage[0] = pipelineStage;
}

//  IF1, IF2, ID, EXE1, EXE2, MEM1, MEM2, WB.


// call a function for each instruction to which you pass the destination register number, if any, as well as the earliest stage in which the result will become available

static void registerArr(int reg, int *destReg)
{
	int i = 7;      // MIGHT NEED TO BE 5 ***
    
	for (i; i >= 0; i--)
		destReg[i + 1] = destReg[i];
    
	destReg[0] = reg;
}

static void stageCompare(int *bubCounter, int reg, int readyStage, int *destReg, int *readyStage) //COMPARING STAGES: CURRENT READ TO PREVIOUSLY WRITTEN
{
	int i = 0;
	int bubTemp = 0;
    
	for(i; i < 8; ++i)      /// for less than 8 stages assign
	{
		if(destReg[i] == reg)
			break;
	}
    
    // check to see - Whenever an instruction needs to read an input register, determine, based on the content of the two arrays, whether it will be able to do so in time (either from the register file or from the forwarding network) or whether it has to wait, in which case the appropriate number of bubbles needs to be inserted
    
	if(readyStage[i] - (readyStage <= 0)) //NO FORWARDING NEEDED (CHECK FOR REDUNDANCY)
	{
		//If this empty conditional statement is not here, it would segfault because it would try to insert zero or negative amount of bubbles, which would cause an exception.
    }
	else
	{
		bubTemp = (readyStage[i] - readyStage); // get numberic number of bubbles needed = subtract the               results number - the stage that it is ready
        
		*(bubCounter) += bubTemp; // add numberic value to bubble counter
        
		while(bubTemp != 0) // while the bubble counter still have values stall the pipeline by calling stall
		{
			registerArr(-1, destReg);
			isReady(-1, readyStage);
            
			--bubTemp;
		}
	}
}



//  IF1, IF2, ID, EXE1, EXE2, MEM1, MEM2, WB.

static void Interpret(int start)
{
  register int instr, opcode, rs, rt, rd, shamt, funct, uimm, simm, addr;
  register int pc, hi, lo;
  int reg[32];
  register int cont = 1, count = 0;
  register long long wide;

  //--------------------------------------
  //COUNTERS
    
  int bubCounter = 0;        // counts bubbles inserted
  int fluCounter = 0;         // counts flushes
  int cycCounter = 0;         // counts cycles
    
  int readyStage[8] = {0};       // an array that show the earliest stage that the result is ready
  int destReg[8] = {0};          // destionation register array for each pipeline
    
  int *bubCounterPtr = &bubCounter;   // pointer to the bubble counter
   
    
    
  pc = start;
  reg[28] = 0x10008000;  // gp
  reg[29] = 0x10000000 + MEMSIZE;  // sp

    //  IF1, IF2, ID, EXE1, EXE2, MEM1, MEM2, WB.
    
  while (cont) {
    count++;
    instr = Fetch(pc);
    pc += 4;
    reg[0] = 0;  // $zero

    opcode = (unsigned)instr >> 26;
    rs = (instr >> 21) & 0x1f;
    rt = (instr >> 16) & 0x1f;
    rd = (instr >> 11) & 0x1f;
    shamt = (instr >> 6) & 0x1f;
    funct = instr & 0x3f;
    uimm = instr & 0xffff;
    simm = ((signed)uimm << 16) >> 16;
    addr = instr & 0x3ffffff;

    // 8 Stage Pipeline
    // CONSTANT 1 = IF1 (Instruction Fetch STAGE 1)
    // CONSTANT 2 = IF2 (Instruction Fetch STAGE 2)
    // CONSTANT 3 = ID   (Instruction Decode)
    // CONSTANT 4 = EXE1 (Execute Stage 1)
    // CONSTANT 5 = EXE2 (Execute Stage 2)
    // CONSTANT 6 = MEM1 (MEM STAGE 1)
    // CONSTANT 7 = MEM2 (MEM STAGE 2)
    // CONSTANT 8 = WB   (Write Back)
     
    // constant in stageCompare is when the input for instruction is needed
    // constant in isReady is when the result becomes available
      
    switch (opcode) {
      case 0x00:
        switch (funct) {
            case 0x00: /* sll */ reg[rd] = reg[rs] << shamt;
				stageCompare(bubCounterPtr, rs, 4, destReg, readyStage); // instruction input is needed at stage 4
				registerArr(rd, destReg);
				isReady(5, readyStage);                                  // results is ready at the end of stage 5
				break;
                
			case 0x03: /* sra */ reg[rd] = reg[rs] >> shamt;
				stageCompare(bubCounterPtr, rs, 4, destReg, readyStage);
				registerArr(rd, destReg);
				isReady(5, readyStage);
				break;
                
			case 0x08: /* jr */ pc = reg[rs]; //fake value inserted
				fluCounter += 2;
				stageCompare(bubCounterPtr, rs, 3, destReg, readyStage); // need the input for the instruciton in id stage (3) = readyStage
				registerArr(-1, destReg);
				isReady(-1, readyStage);
				break;
                
			case 0x10: /* mfhi */ reg[rd] = hi;
				stageCompare(bubCounterPtr, 33, 4, destReg, readyStage);
				registerArr(rd, destReg);
				isReady(7, readyStage); // takes 7 cycles for result to be available - WB stage
				break;
                
			case 0x12: /* mflo */ reg[rd] = lo;
				stageCompare(bubCounterPtr, 33, 4, destReg, readyStage);
				registerArr(rd, destReg);
				isReady(7, readyStage);
				break;
    
                //  IF1, IF2, ID, EXE1, EXE2, MEM1, MEM2, WB.

                
			case 0x18: /* mult */ wide = reg[rs]; wide *= reg[rt]; lo = wide & 0xffffffff; hi = wide >> 32;
				stageCompare(bubCounterPtr, rs, 4, destReg, readyStage);
				stageCompare(bubCounterPtr, rt, 4, destReg, readyStage);
				registerArr(33, destReg);
				isReady(7, readyStage);
				break;
                
			case 0x1a: /* div */
				if (reg[rt] == 0)       // check for division by 0
				{
					fprintf(stderr, "division by zero: pc = 0x%x\n", pc-4);
					cont = 0;
					stageCompare(bubCounterPtr, rt, 4, destReg, readyStage);
					registerArr(-1, destReg);
					isReady(-1, readyStage);
				}
				else                    // handle normal divison
				{
					lo = reg[rs] / reg[rt];
					hi = reg[rs] % reg[rt];
					stageCompare(bubCounterPtr, rs, 4, destReg, readyStage);
					stageCompare(bubCounterPtr, rt, 4, destReg, readyStage);
					registerArr(33, destReg);
					isReady(7, readyStage);
				}
				break;
                
			case 0x21: /* addu */ reg[rd] = reg[rs] + reg[rt];
				stageCompare(bubCounterPtr, rs, 4, destReg, readyStage);
				stageCompare(bubCounterPtr, rt, 4, destReg, readyStage);
				registerArr(rd, destReg);
				isReady(5, readyStage);
				break;
                
			case 0x23: /* subu */ reg[rd] = reg[rs] - reg[rt];
				stageCompare(bubCounterPtr, rs, 4, destReg, readyStage);
				stageCompare(bubCounterPtr, rt, 4, destReg, readyStage);
				registerArr(rd, destReg);
				isReady(5, readyStage); // stall til 5 that is when results ready
				break;
                
			case 0x2a: /* slt */
				if(reg[rs] < reg[rt])
				{
					reg[rd] = 1;
					stageCompare(bubCounterPtr, rs, 4, destReg, readyStage);
					stageCompare(bubCounterPtr, rt, 4, destReg, readyStage);
					registerArr(rd, destReg);
					isReady(5, readyStage);
				}
                else
				{
					reg[rd] = 0;
				}
				break;
                
			default: fprintf(stderr, "unimplemented instruction: pc = 0x%x\n", pc-4); cont = 0;
		}
        break;
            
        case 0x02: /* j */ pc = (pc & 0xf0000000) + addr * 4;
            fluCounter += 2;
            registerArr(-1, destReg);
            isReady(-1, readyStage);
            break;
            
        case 0x03: /* jal */ reg[31] = pc; pc = (pc & 0xf0000000) + addr * 4;
            fluCounter += 2;
            registerArr(31, destReg); // return address and dest regster
            isReady(3, readyStage);       // results is ready at the end of id stage
            break;
            
        case 0x04: /* beq */
            if (reg[rs] == reg[rt])
            {
                pc = pc + (simm*4);
                fluCounter += 2;
                stageCompare(bubCounterPtr, rs, 3, destReg, readyStage); // need input at stage 3
                stageCompare(bubCounterPtr, rt, 3, destReg, readyStage);
                registerArr(-1, destReg);
                isReady(-1, readyStage);
            }
            else
            {
                pc = pc;
            }
            break;
            
        case 0x05: /* bne */
            if (reg[rs] != reg[rt])
            {
                pc = pc + (simm*4);
                fluCounter += 2;
                stageCompare(bubCounterPtr, rs, 3, destReg, readyStage); // need input at stage 3
                stageCompare(bubCounterPtr, rt, 3, destReg, readyStage);
                registerArr(-1, destReg);
                isReady(-1, readyStage);
            }
            else
            {
                pc = pc;
            }
            break;
            
        case 0x09: /* addiu */ reg[rt] = reg[rs] + simm;
            stageCompare(bubCounterPtr, rs, 4, destReg, readyStage);
            registerArr(rt, destReg);
            isReady(5, readyStage);       // ready at 5 because that is the end of their execution
            break;
            
        case 0x0c: /* andi */ reg[rt] = reg[rs] & uimm;
            stageCompare(bubCounterPtr, rs, 4, destReg, readyStage);
            registerArr(rt, destReg);
            isReady(5, readyStage);   // ready at 5 because that is the end of their execution
            break;
            
        case 0x0f: /* lui */ reg[rt] = simm << 16;
            registerArr(rt, destReg);
            isReady(5, readyStage);   // ready at 5 because that is the end of their execution
            break;
 
            //  IF1, IF2, ID, EXE1, EXE2, MEM1, MEM2, WB.

            
        case 0x1a: /* trap */
            switch (addr & 0xf) {
                case 0x00: printf("\n");
                    break;
					
                case 0x01: printf(" %d", reg[rs]);
                    stageCompare(bubCounterPtr, rs, 4, destReg, readyStage);
                    registerArr(-1, destReg);
                    isReady(-1, readyStage);
                    break;
                    
                case 0x05: printf("\n? "); fflush(stdout); scanf("%d", &reg[rt]);
                    registerArr(rt, destReg);
                    isReady(5, readyStage);
                    break;
                    
                case 0x0a: cont = 0; 
                    break;
					
                default: fprintf(stderr, "unimplemented trap: pc = 0x%x\n", pc-4); cont = 0;
            }
            break;
            
        case 0x23: /* lw */ reg[rt] = LoadWord(reg[rs] + simm);
            stageCompare(bubCounterPtr, rs, 4, destReg, readyStage);
            registerArr(rt, destReg);
            isReady(7, readyStage);       // lw result becomes available in WB at the end of MEM2
            break;
           
            //  IF1, IF2, ID, EXE1, EXE2, MEM1, MEM2, WB.
    
            
        case 0x2b: /* sw */ StoreWord(reg[rt] ,(reg[rs] + simm));
            stageCompare(bubCounterPtr, rt, 7, destReg, readyStage);  // sw is needed in mem1 stage
            stageCompare(bubCounterPtr, rs, 7, destReg, readyStage);
            registerArr(-1, destReg);
            isReady(-1, readyStage);
            break;
            
        default: fprintf(stderr, "unimplemented instruction: pc = 0x%x\n", pc-4); cont = 0;
    }
  }
    

  printf("\nprogram finished at pc = 0x%x  (%d instructions executed)\n", pc, count);

    //COUNT IMPLEMENTATION
    cycCounter = (count + 7) + bubCounter + fluCounter;
    
    //PRINTING
    printf("Total Number of Cycles = %i \n", cycCounter);
    printf("Total Number of Bubbles = %i \n", bubCounter);
    printf("Total Number of Flushes = %i \n", fluCounter);
}


int main(int argc, char *argv[])
{
  int c, start;
  FILE *f;

  printf("CS3339 -- MIPS Runtime Simulator - Cycles.c\n");
  if (argc != 2) {fprintf(stderr, "usage: %s executable\n", argv[0]); exit(-1);}
  if (sizeof(int) != 4) {fprintf(stderr, "error: need 4-byte integers\n"); exit(-1);}
  if (sizeof(long long) != 8) {fprintf(stderr, "error: need 8-byte long longs\n"); exit(-1);}

  c = 1;
  little_endian = *((char *)&c);
  f = fopen(argv[1], "r+b");
  if (f == NULL) {fprintf(stderr, "error: could not open file %s\n", argv[1]); exit(-1);}
  c = fread(&icount, 4, 1, f);
  if (c != 1) {fprintf(stderr, "error: could not read count from file %s\n", argv[1]); exit(-1);}
  if (little_endian) {
    icount = Convert(icount);
  }
  c = fread(&start, 4, 1, f);
  if (c != 1) {fprintf(stderr, "error: could not read start from file %s\n", argv[1]); exit(-1);}
  if (little_endian) {
    start = Convert(start);
  }

  instruction = (int *)(malloc(icount * 4));
  if (instruction == NULL) {fprintf(stderr, "error: out of memory\n"); exit(-1);}
  c = fread(instruction, 4, icount, f);
  if (c != icount) {fprintf(stderr, "error: could not read (all) instructions from file %s\n", argv[1]); exit(-1);}
  fclose(f);
  if (little_endian) {
    for (c = 0; c < icount; c++) {
      instruction[c] = Convert(instruction[c]);
    }
  }

  printf("running %s\n\n", argv[1]);
  Interpret(start);
}

