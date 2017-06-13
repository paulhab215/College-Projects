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



static void Ready(int pipeStage, int *sReady)
{
	int i = 0;
	int x = 7; // iterators

	for (i; i < 8; ++i)   /// loop through 8 stages
	{
		if((sReady[i] - 1) >= 0)
			sReady[i] = (sReady[i] - 1);
		else
			sReady[i] = 0;
	}

	for (x; x >= 0; --x)
		sReady[x + 1] = sReady[x];
	
	sReady[0] = pipeStage;
}

static void regArray(int reg, int *destReg)
{
	int i = 7;

	for (i; i >= 0; i--)
		destReg[i + 1] = destReg[i];

	destReg[0] = reg;
}

static void compareStages(int *bubbleCounter, int reg, int readyStage, int *destReg, int *sReady) //compare stages: read to previous written
{
	int i = 0;
	int bubbleTempVar = 0;

	for(i; i < 8; ++i)   /// loop through 8 stages
	{
		if(destReg[i] == reg)
			break;
	}
    
        // check to see - Whenever an instruction needs to read an input register, determine, based on the content of the two arrays, whether it will be able to do so in time (either from the register file or from the forwarding network) or whether it has to wait, in which case the appropriate number of bubbles needs to be inserted

	if(sReady[i] - readyStage <= 0) //Do not need forwarding
	{
		// Empty conditional statement to prevent segmentation fault. Without this statement it would try to negative number of bubbles, causing an exception.	
    }
	else
	{
		bubbleTempVar = (sReady[i] - readyStage); // get numberic number of bubbles needed = subtract the results number - the stage that it is ready
		(*bubbleCounter) += bubbleTempVar; // add numeric value to bubble counter
        


		while(bubbleTempVar != 0)
		{
			regArray(-1, destReg);
			Ready(-1, sReady);

			--bubbleTempVar;
		}
	}
}

static void Interpret(int start)
{
  register int instr, opcode, rs, rt, rd, shamt, funct, uimm, simm, addr;
  register int pc, hi, lo;
  int reg[32];
  register int cont = 1, count = 0;
  register long long wide;
    
  //--------------------------------------
  //COUNTERS
  int bubbleCounter = 0;    // counts bubbles
  int flushCounter = 0;     // counts flushe
  int cycleCounter = 0;     // counts cycles
    
  //----------------------------------------
    // 2 arrays that represent the pipeline stages

  int sReady[8] = {0}; // array records which stage it generates result
  int destReg[8] = {0}; // destination register array for each instruction in pipeline

  int *bubbleCounterPtr = &bubbleCounter;  // pointer to the bubble counter

  pc = start;
  reg[28] = 0x10008000;  // gp
  reg[29] = 0x10000000 + MEMSIZE;  // sp

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
				compareStages(bubbleCounterPtr, rs, 4, destReg, sReady); // instruction input is needed at stage 4
				regArray(rd, destReg);
				Ready(5, sReady);
				break;

			case 0x03: /* sra */ reg[rd] = reg[rs] >> shamt;
				compareStages(bubbleCounterPtr, rs, 4, destReg, sReady);
				regArray(rd, destReg);
				Ready(5, sReady); // results is ready at the end of stage 5

				break;

			case 0x08: /* jr */ pc = reg[rs]; //fake value inserted
				flushCounter += 2;
				compareStages(bubbleCounterPtr, rs, 3, destReg, sReady); // need the input for the instruciton in id stage (3) = readyStage

				regArray(-1, destReg);
				Ready(-1, sReady);
				break;

			case 0x10: /* mfhi */ reg[rd] = hi; 
				compareStages(bubbleCounterPtr, 33, 4, destReg, sReady);
				regArray(rd, destReg);
				Ready(7, sReady);    // takes 7 cycles for result to be available - WB stage
				break;

			case 0x12: /* mflo */ reg[rd] = lo;
				compareStages(bubbleCounterPtr, 33, 4, destReg, sReady);
				regArray(rd, destReg);
				Ready(7, sReady);
				break;
                
                //  IF1, IF2, ID, EXE1, EXE2, MEM1, MEM2, WB.
   

			case 0x18: /* mult */ wide = reg[rs]; wide *= reg[rt]; lo = wide & 0xffffffff; hi = wide >> 32;
				compareStages(bubbleCounterPtr, rs, 4, destReg, sReady);
				compareStages(bubbleCounterPtr, rt, 4, destReg, sReady);
				regArray(33, destReg);
				Ready(7, sReady);
				break;				
			
			case 0x1a: /* div */  // check for division by 0
				if (reg[rt] == 0)
				{
					fprintf(stderr, "division by zero: pc = 0x%x\n", pc-4);
					cont = 0;
					compareStages(bubbleCounterPtr, rt, 4, destReg, sReady);
					regArray(-1, destReg);
					Ready(-1, sReady);
				}
				else                    // handle normal divison
				{
					lo = reg[rs] / reg[rt]; 
					hi = reg[rs] % reg[rt];
					compareStages(bubbleCounterPtr, rs, 4, destReg, sReady);
					compareStages(bubbleCounterPtr, rt, 4, destReg, sReady);
					regArray(33, destReg);
					Ready(7, sReady);
				}
				break;

			case 0x21: /* addu */ reg[rd] = reg[rs] + reg[rt];
				compareStages(bubbleCounterPtr, rs, 4, destReg, sReady);
				compareStages(bubbleCounterPtr, rt, 4, destReg, sReady);
				regArray(rd, destReg);
				Ready(5, sReady);
				break;

			case 0x23: /* subu */ reg[rd] = reg[rs] - reg[rt];
				compareStages(bubbleCounterPtr, rs, 4, destReg, sReady);
				compareStages(bubbleCounterPtr, rt, 4, destReg, sReady);
				regArray(rd, destReg);
				Ready(5, sReady);
				break;

			case 0x2a: /* slt */ 
				if(reg[rs] < reg[rt])
				{	
					reg[rd] = 1;
					compareStages(bubbleCounterPtr, rs, 4, destReg, sReady);
					compareStages(bubbleCounterPtr, rt, 4, destReg, sReady);
					regArray(rd, destReg);
					Ready(5, sReady);
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
				flushCounter += 2;
				regArray(-1, destReg);
				Ready(-1, sReady);
				break;

			case 0x03: /* jal */ reg[31] = pc; pc = (pc & 0xf0000000) + addr * 4;
				flushCounter += 2;
				regArray(31, destReg);
				Ready(3, sReady);
				break;

			case 0x04: /* beq */ 
				if (reg[rs] == reg[rt])
				{
					pc = pc + (simm*4); 
					flushCounter += 2;
					compareStages(bubbleCounterPtr, rs, 3, destReg, sReady);
					compareStages(bubbleCounterPtr, rt, 3, destReg, sReady);
					regArray(-1, destReg);
					Ready(-1, sReady);
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
					flushCounter += 2;
					compareStages(bubbleCounterPtr, rs, 3, destReg, sReady);
					compareStages(bubbleCounterPtr, rt, 3, destReg, sReady);
					regArray(-1, destReg);
					Ready(-1, sReady);
				}
				else
				{
					pc = pc;
				}
					break;

			case 0x09: /* addiu */ reg[rt] = reg[rs] + simm;
				compareStages(bubbleCounterPtr, rs, 4, destReg, sReady);
				regArray(rt, destReg);
				Ready(5, sReady);
				break;

			case 0x0c: /* andi */ reg[rt] = reg[rs] & uimm;
				compareStages(bubbleCounterPtr, rs, 4, destReg, sReady);
				regArray(rt, destReg);
				Ready(5, sReady);
				break;

			case 0x0f: /* lui */ reg[rt] = simm << 16;
				regArray(rt, destReg);
				Ready(5, sReady);
				break;

			case 0x1a: /* trap */
				switch (addr & 0xf) {
					case 0x00: printf("\n");
						break;
					
					case 0x01: printf(" %d", reg[rs]);
						compareStages(bubbleCounterPtr, rs, 4, destReg, sReady);
						regArray(-1, destReg);
						Ready(-1, sReady);
						break;

					case 0x05: printf("\n? "); fflush(stdout); scanf("%d", &reg[rt]);
						regArray(rt, destReg);
						Ready(5, sReady);
						break;

					case 0x0a: cont = 0; 
						break;
					
					default: fprintf(stderr, "unimplemented trap: pc = 0x%x\n", pc-4); cont = 0;
				}
				break;
      
			case 0x23: /* lw */ reg[rt] = LoadWord(reg[rs] + simm);
				compareStages(bubbleCounterPtr, rs, 4, destReg, sReady);
				regArray(rt, destReg);
				Ready(7, sReady);  // lw result becomes available in WB at the end of MEM2
				break;
            
            //  IF1, IF2, ID, EXE1, EXE2, MEM1, MEM2, WB.


			case 0x2b: /* sw */ StoreWord(reg[rt] ,(reg[rs] + simm));
				compareStages(bubbleCounterPtr, rt, 7, destReg, sReady); // sw is needed in mem1 stage
				compareStages(bubbleCounterPtr, rs, 7, destReg, sReady);
				regArray(-1, destReg);
				Ready(-1, sReady);
				break;

			default: fprintf(stderr, "unimplemented instruction: pc = 0x%x\n", pc-4); cont = 0;
			}
		}

  printf("\nprogram finished at pc = 0x%x  (%d instructions executed)\n", pc, count);


//Solve cycle count
cycleCounter = (count + 7) + bubbleCounter + flushCounter;

    //print results
printf("Total Number of Cycles = %i \n", cycleCounter);
printf("Total Number of Bubbles = %i \n", bubbleCounter);
printf("Total Number of Flushes = %i \n", flushCounter);
}

int main(int argc, char *argv[])
{
  int c, start;
  FILE *f;

  printf("CS3339 MIPS Cycles - Runtime Simulator\n");
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
